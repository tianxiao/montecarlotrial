// the flag class may need do the bit operator 
// to save some memeory 
// here I just use the std::vector<txFlag> to do
// the job, may consume more memory than the bit operator
// If it is diefficiency, I'll changed it to the bit operator.
//#include <vector>
#ifndef _TXTYPE_HEADERFILE_
#define _TXTYPE_HEADERFILE_
#include <assert.h>
#include <list>
#define txFlag unsigned long 

class txFlags
{
public:
	txFlags(void);
	
	~txFlags(void);

	void Add(const txFlag &flag){
		bool exist = IsExist(flag);
		if (!exist){
			flags.push_back(flag);
		}
	}
	void Remove(const txFlag &flag){
		bool exist = IsExist(flag);
		if (!exist){
			assert(false);
		}

		// TODO remove should be Efficient 
		// If consider with the IsExist.
		flags.remove(flag);

	}

private:
	bool IsExist(const txFlag &flag){
		bool exist = false;
		std::list<txFlag>::iterator it=flags.begin();
		for (;it!=flags.end(); it++){
			if (*it==flag) exist = true;
		}
		return exist;
	}

private:
	std::list<txFlag> flags;
};

#endif
