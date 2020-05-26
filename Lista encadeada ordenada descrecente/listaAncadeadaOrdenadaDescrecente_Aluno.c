#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct tipoElemento{
	float nota;
	char nome[20];
	struct tipoElemento *proximo;
}TElemento;

typedef struct tipoLista{
	TElemento *inicio;
	TElemento *fim;
}TLista;

void inicializar(TLista *p)
{
	p->inicio = NULL;
	p->fim = NULL;
}
void inserir(TLista *p)
{
	TElemento *novo;
	novo = (TElemento *) malloc(sizeof(TElemento));
	
	printf("Nome: ");
	fflush(stdin);
	gets(novo->nome);
	printf("Nota: ");
	scanf("%f", &novo->nota);
	novo->proximo = NULL;
		
	if(p->inicio == NULL)
	{
		p->inicio = novo;
		p->fim = novo;
	}
	else 
	{
		if(novo->nota > p->inicio->nota)
		{
			novo->proximo = p->inicio;
			p->inicio = novo;
		}
		else
		{
			if(novo->nota <= p->fim->nota)
			{
				p->fim->proximo = novo;
				p->fim = novo;
			}
			else
			{
				TElemento *anterior, *atual;
				anterior = p->inicio;
				atual = p->inicio->proximo;
				while(atual != NULL)
				{
					if( atual->nota < novo->nota)
					{
						novo->proximo = atual;
						anterior->proximo = novo;
						break;
					}
					else
					{
						anterior = atual;
						atual = atual->proximo;
					}
				}
			}
		}
	}
	
	
}

	
void apresentar (TLista *p)
{
	TElemento *aux;
	aux = p->inicio;
	printf("\nRelatorio\n============\n");
	while (aux != NULL)
	{
		printf("Nome..: %s\n", aux->nome);
		printf("Nota..: %1.f\n",aux->nota);
		printf("\n");
		aux = aux->proximo;
	}
	
}

int main(int argc, char *argv[]) {
	int op;
	TLista L;
	inicializar(&L);
	do
	{
		printf("\nMenu\n");
		printf("1- Inserir Aluno\n");
		printf("2- Apresentar Alunos\n");
		printf("0- Sair\n");
		printf("\n");
		printf("Opcao: ");
		scanf("%d", &op);
		switch(op)
		{
			case 1: inserir(&L); break;
			case 2: apresentar(&L); break;
		}
	}while(op != 0);
}
