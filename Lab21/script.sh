#! /bin/bash

function Flags {
    while [ -n "$1" ]
        do
            case "$1" in
                -directory|-dir|-d) dir="$2"; shift ;;
                -h|--help|-help) help;exit 0; break;;
                --) shift; break ;;
                *) echo "$1 is not an option";;
            esac
            shift
        done
}

function help {
    echo ""
    echo "counts unique suffixes and displays them"
    echo ""
}

function checkFlags {
    undefinedFlag=0
    if [[ $1 = "undefined" ]]
    then
        echo "dir is undefined"
        undefinedFlag=1
    fi
    if [[ $undefinedFlag -eq 1  ]]
    then
        exit 0
    fi
}

function main {
    dir="undefined"
    Flags $@
    checkFlags $dir
    rawSuffixes=$(awk -F/ '{print $NF}' <<< `find $dir -type f -print` | cut -d'.' -f2)
    nDupSuffixes=$(printf "%s\n" "${rawSuffixes[@]}" | sort -u)
    
    wc -w <<< "$nDupSuffixes"
    echo $nDupSuffixes
}


main $@