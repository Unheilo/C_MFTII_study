#include <stdio.h>
#include <ctype.h>
int isvowel(char c);
int main(int argc, char** argv)
{
	FILE* F; int c, letter, cons, vowel, total = 0;

	int perenos, digit, punct, space = 0;
	
		F = fopen("text.txt", "r");
		total = letter = cons = vowel = 0;
		perenos = digit = punct = space = 0;
		while ((c = fgetc(F)) != EOF)
		{
			total++;

			if (c == '\n') {
				perenos++;
			}

			if (isdigit(c)) {
				digit++;
			}

			if (ispunct(c)) {
				punct++;
			}

			if (isspace(c)) {
				space++;
			}

			if (isalpha(c))
			{
				letter++;
				if (isvowel(c)) vowel++;
				else cons++;
			}
		}
		printf("FILE %s: total=%d letters=%d vowels=%d, cons=%d\n", "text.txt", total, letter, vowel, cons);
		printf("perenos=%d, degit=%d, punct=%d, space=%d", perenos, digit, punct, space);
	
	return 0;
}

int isvowel(char c)
{
	c = tolower(c); // приводим символ к нижнему регистру
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		return 1; // символ является гласной
	}
	else {
		return 0; // символ не является гласной
	}

	//switch (tolower(c))
	//{
	//case 'a':
	//case 'e':
	//case 'i':
	//case 'o':
	//case 'u':
	//case 'y': return 1;
	//}
	//return 0;

}
