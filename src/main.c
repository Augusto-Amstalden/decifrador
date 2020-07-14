#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int senha[] = {18, 4, 13, 7, 0, 18, 4, 2, 17, 4, 19, 0};	// SENHASECRETA em ascii
const int senha_t = 12;

int main() {

	char alfabeto[][2] = {"A.", "B.", "C.", "D.", "E.", "F.", "G.", "H.", "I.", "J.", "K.", "L.", "M.", "N.", "O.", "P.", "Q.", "R.", "S.", "T.", "U.", "V.", "W.", "X.", "Y.", "Z."};		
	char texto[1024];
	char palavras[200][25];
	int quantidade = 0;
	int pos = 0;
	int a;
	
	scanf(" %[^\n]", texto);
	char *p = strtok(texto, " ");
	while(p != NULL) {
		a = strlen(p);
		strncpy(palavras[pos++], p, a);
		palavras[pos - 1][a] = '\0';
		quantidade++;
		p = strtok(NULL, " ");
	}
	
	int tamanho;
	int cont = -1;
	int c;
	
	for(int i = 0; i < quantidade; i++) {
		tamanho = strlen(palavras[i]);
		for(int j = 0; j < tamanho; j++) {
			c = 1;
			cont++;				// posiçao na senha
			if(cont >= senha_t) {
				cont = cont - senha_t;
			}
			for(int r = 0; r < 26; r++) {
				if(r + senha[cont] >= 26) {
					if(alfabeto[r + senha[cont] - 26][0] == palavras[i][j]) {
						printf("%c", alfabeto[r][0]);
						c = 0;
						break;
					}
				}
				else {
					if(alfabeto[r + senha[cont]][0] == palavras[i][j]) {
						printf("%c", alfabeto[r][0]);
						c = 0;
						break;
					}
				}
			}
			if(c) {
				printf("%C", palavras[i][j]);
			}
		}
		if(i != quantidade - 1) {
			printf(" ");
		}
		else {
			printf("\n");
		}
		cont++;
	}
}
			
			
			
			
			
			
			
			
			
			
		
	
