#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    float t[8];
    int a0, v0;
    int contador;
} Regis;

void inicializar(Regis *r)
{
    r->contador = 0;
    for (int i = 0; i < 8; i++)
    {
        r->t[i] = 0;
    }
    r->v0 = 0;
    r->a0 = 0;
}

// Função a ser executada ao reconhecer a palavra "alvo"
void funcaoReconhecida(int i, char *linha, Regis *r)
{
    // printf("Palavra 'alvo' reconhecida! Função executada.\n");
    char *registradores[] = {"$T0", "$T1", "$T2", "$T3", "$T4", "$T5", "$T6", "$T7", "$A0", "$V0"};
    // char strings[50];
    char *start;
    char *token;
    int aux[3];

    int a;
    // printf("%s\n", registradores[0]);
    // scanf("%d", &a);
    // switch com as instruções e redirecionamento para execução da instrução
    switch (i)
    {
    case 0:
        // Usando strtok para dividir a string em tokens
        token = strtok(linha, ",");

        // Loop para percorrer todos os tokens
        int k = 0;
        while (token != NULL)
        {
            // Faça alguma coisa com o token, por exemplo, imprimir na tela
            // printf("%s\n", token);
            for (int j = 0; j < 8; j++)
            {
                if (strstr(token, registradores[j]) != NULL)
                {
                    aux[k] = j;
                    k++;
                }
            }

            // Obtenha o próximo token
            token = strtok(NULL, ",");
        }
        r->t[aux[0]] = r->t[aux[1]] + r->t[aux[2]];
        printf("\n %.2f\n", r->t[aux[0]]);
        scanf("%d", &a);
        break;
    case 1:
        printf("Um\n");
        break;
    case 2:
        printf("Dois\n");
        break;
    case 3:
        printf("Três\n");
        break;
    case 4:
        printf("Quatro\n");
        break;
    case 5:
        printf("Cinco\n");
        break;
    case 6:
        printf("Seis\n");
        break;
    case 7:
        printf("Sete\n");
        break;
    case 8:
        printf("Oito\n");
        break;
    case 9:
        printf("Nove\n");
        break;
    case 10:
        printf("Dez\n");
        break;
    case 11:
        printf("Onze\n");
        break;
    case 12:
        printf("Doze\n");
        break;
    case 13:
        printf("Treze\n");

        for (int j = 0; j < 8; j++)
        {
            // printf("%s\n", registradores[j]);
            if (strstr(linha, registradores[j]) != NULL)
            {
                // Se a palavra for encontrada, executar a função
                switch (j)
                {
                case 0:
                    // t0

                    // Usando strtok para dividir a string em tokens
                    token = strtok(linha, ",");

                    // Loop para percorrer todos os tokens
                    while (token != NULL)
                    {
                        // Faça alguma coisa com o token, por exemplo, imprimir na tela
                        r->t[0] = atoi(token);
                        // Obtenha o próximo token
                        token = strtok(NULL, ",");
                    }
                    // printf("%.2f\n", r->t0);
                    // scanf("%d", &a);
                    break;
                case 1:
                    // t1
                    //  Usando strtok para dividir a string em tokens
                    token = strtok(linha, ",");

                    // Loop para percorrer todos os tokens
                    while (token != NULL)
                    {
                        // Faça alguma coisa com o token, por exemplo, imprimir na tela
                        r->t[1] = atoi(token);
                        // Obtenha o próximo token
                        token = strtok(NULL, ",");
                    }
                    // printf("%.2f\n", r->t1);
                    // scanf("%d", &a);
                    break;
                case 2:
                    // t2
                    break;
                case 3:
                    // t3
                    break;
                case 4:
                    // t4
                    break;
                case 5:
                    // t5
                    break;
                case 6:
                    // t6
                    break;
                case 7:
                    // t7
                    break;
                case 8:
                    // v0
                    //  Usando strtok para dividir a string em tokens
                    token = strtok(linha, ",");

                    // Loop para percorrer todos os tokens
                    while (token != NULL)
                    {
                        // Faça alguma coisa com o token, por exemplo, imprimir na tela
                        r->v0 = atoi(token);
                        // Obtenha o próximo token
                        token = strtok(NULL, ",");
                    }
                    // printf("%d\n", v0);
                    // scanf("%d", &a);
                    switch (r->v0)
                    {
                    case 1:
                        // printf
                        break;

                    case 5:
                        // scanf
                        break;
                    case 10:
                        // sair
                        break;

                    default:
                        break;
                    }
                    break;

                default:
                    printf("Número fora da faixa de 0 a 8\n");
                    break;
                }
            }
        }

        break;
    case 14:
        printf("Catorze\n");
        break;
    case 15:
        printf("Quinze\n");
        break;
    case 16:
        printf("Dezesseis\n");
        break;
    case 17:
        printf("Dezessete\n");
        break;
    case 18:
        printf("Dezoito\n");
        break;
    case 19:
        printf("Dezenove\n");
        break;
    case 20:
        printf("Vinte\n");
        break;
    case 21:
        printf("Vinte e um\n");
        break;
    case 22:
        printf("Vinte e dois\n");
        break;
    case 23:
        printf("Vinte e três\n");
        break;
    case 24:
        printf("Vinte e quatro\n");
        break;
    case 25:
        // Encontrando o primeiro par de aspas
        start = strchr(linha, '\"');

        // Verificando se as aspas foram encontradas
        if (start != NULL)
        {
            // Encontrando o segundo par de aspas
            char *end = strchr(start + 1, '\"');

            // Verificando se o segundo par de aspas foi encontrado
            if (end != NULL)
            {
                // Calculando o comprimento do texto entre as aspas
                size_t length = end - start - 1;

                // Criando um buffer para armazenar o texto entre as aspas
                char string[2][length + 1];

                // Copiando o texto entre as aspas para o buffer
                strncpy(string[r->contador], start + 1, length);
                string[r->contador][length] = '\0'; // Adicionando o caractere nulo no final

                // Imprimindo o resultado
                printf("string[%d]: %s\n", r->contador, string[r->contador]);
                r->contador++;
            }
        }
        break; /*
     case 26:
         printf("Vinte e seis\n");
         break;
     case 27:
         printf("Vinte e sete\n");
         break;
     case 28:
         printf("Vinte e oito\n");
         break;
     case 29:
         printf("Vinte e nove\n");
         break;
     case 30:
         printf("Trinta\n");
         break;
     case 31:
         printf("Trinta e um\n");
         break;*/
    default:
        printf("Número fora da faixa de 0 a 31\n");
        break;
    }
}

int main()
{
    Regis r;
    inicializar(&r);
    char instrucoes[26][10] = {"ADD", "ADDI", "SUB", "SUBI", "MULT", "DIV", "AND", "OR", "XOR", "NOR", "SLT", "SLL", "SRA", "LI",
                               "LW", "SW", "LB", "SB", "BEQ", "BNE", "BGT", "BEZ", "J", "JR", "JAL", ".ASCIIZ"};

    const char *nomeArquivo = "codigoMIPS.s";
    FILE *arquivo = fopen("codigoMIPS.s", "r");

    if (arquivo == NULL)
    {
        fprintf(stderr, "Erro ao abrir o arquivo %s\n", nomeArquivo);
        return 1;
    }

    char linha[1000];

    int conta = 0;
    // Loop para ler cada linha do arquivo
    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        // Verificar se a palavra "alvo" está presente na linha
        // Converter a string para maiúsculas
        for (int i = 0; i < (int)strlen(linha); i++)
        {
            linha[i] = toupper(linha[i]);
        }

        for (int i = 0; i < 26; i++)
        {
            if (strstr(linha, instrucoes[i]) != NULL)
            {
                // Se a palavra for encontrada, executar a função
                conta++;
                printf("%d", conta);
                funcaoReconhecida(i, linha, &r);
            }
        }

        // Imprimir a linha (opcional)
        // printf("%d %s",conta, linha);
    }

    fclose(arquivo);

    return 0;
}