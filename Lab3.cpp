#include<cctype>   		
#include<iostream>
using namespace std;
class Alpha {
	unsigned _bin;
public:
	Alpha() { _bin = 0; };
	Alpha(char*);
	Alpha operator +(Alpha& b);
	Alpha operator -(Alpha& b);
	operator char* ();
	friend ostream& operator <<(ostream&, Alpha&);
};

Alpha::Alpha(char* s) {
	_bin = 0;
	while (*s) {
		if ((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z'))
			_bin |= (1 << (tolower(*s) - 'a'));
		s++;
	}
};
Alpha Alpha::operator+(Alpha& b)
{
	Alpha result;
	result._bin = _bin | b._bin;
	return result;
}

Alpha Alpha::operator-(Alpha& b)
{
	Alpha result;
	unsigned t = _bin & b._bin;
	result._bin = _bin - t;
	return result;
}

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

ostream& operator<<(ostream& out, Alpha& z) {
	unsigned bit = 1;
	for (int i = 0; i < 26; i++) {
		if ((z._bin & bit) > 0)
			out << (char)('a' + i);
		bit = bit << 1;
	}
	return out;
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	if (argc < 2)
	{
		printf("Error write 2 words: ./a.out qweas dsad");
		exit(1);
	}
	Alpha x(argv[1]);
	Alpha y(argv[2]);
	Alpha m = x - y;
	Alpha n = y - x;
	Alpha z = n + m;
	cout << "Объединение двух результатов operator- : " << (char*)z;
	return 0;
}