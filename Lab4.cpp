#include<cctype>   	
#include<iostream>
#include<string>
#define NUMBER 67108863
using namespace std;

class Alpha {
	unsigned _bin;
public:
	Alpha() { _bin = 0; };
	Alpha(const char*);
	int operator ,(Alpha&);
	Alpha operator ~();
	int pop(unsigned);
	operator char* ();
};

Alpha::Alpha(const char* s) {
	_bin = 0;
	while (*s) {
		_bin |= (1 << (tolower(*s) - 'a'));
		s++;
	}
};

Alpha::operator char* () {
	static char s[32];
	unsigned w = _bin;
	int i = 0, j = 0;
	while (w > 0) {
		if (w & 1) {
			s[j++] = 'a' + i;
		}
		i++;
		w = w >> 1;
	}
	s[j++] = '\n';
	s[j] = '\0';
	return (s);
}

int Alpha::operator,(Alpha& y) {
	return pop(_bin & y._bin);
}

int Alpha::pop(unsigned b) {
	int i = 0;
	while (b != 0) {
		b = b & (b - 1);
		i++;
	}
	return(i);
}

Alpha Alpha::operator ~() {
	_bin = NUMBER ^ _bin;
	return *this;
}

int main(int argc, const char** argv) {

	if (argc < 2)
	{
		argv[1] = " ";
	}
	int b;
	Alpha x(argv[1]);
	Alpha A("AEIOU");
	Alpha B = ~A;
	b = (x, B);
	cout << b << endl;
	return 0;
}
