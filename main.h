#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

typedef		struct{char _[32];}		string;
typedef		enum{false, true}		bool;
typedef		enum{EXEC_EXIT = -1, EXEC_CONTINUE, EXEC_WARN}		exec_t;
enum{OKK};
#define		nullptr		((void*)0)

#endif // MAIN_H_INCLUDED
