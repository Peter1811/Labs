enum State: unsigned { Start=0, Slash, Star, Star_Word, Letter, Space, Word, Error};
State WordCount(const State, const int); 
