#include <stdio.h>

int main()
{
	printf("alterado.\n");
	//mudança feita no codeblocks para a branch calculadora
	//alteração na calculadora

    unsigned long i, j, dias_do_mes, mes_do_ano, dia_inicial, mes_inicial, ano_inicial, dia_final, mes_final, ano_final;
    unsigned long ano, mes, primeiro_dia_do_mes, cont_dias = 0, k, dias_a_somar, opcao;

    void ler_arquivo_gas_txt();
    ler_arquivo_gas_txt();

    printf("Calculadora de datas.\n");
    printf("Escolha a operacao que deseja realizar.\n");
    printf("Digite 1 para calcular a diferenca em dias entre duas datas.\n");
    printf("Digite 2 para adcionar dias apartir de uma data especifica.\n");
    scanf("%lu", &opcao);
    if(opcao == 1)
    {
         printf("Calcular diferencas entre duas datas em dias.\n");
         printf("Digite as datas no formato dd/mm/aaaa exemplo 21/05/1989.\n");
         printf("Digite a data inicial.\n");
         scanf("%lu/%lu/%lu", &dia_inicial, &mes_inicial, &ano_inicial);
         printf("Digite a data final.\n");
         scanf("%lu/%lu/%lu", &dia_final, &mes_final, &ano_final);
    }
    else
    {
        printf("Adicionar dias a uma data especifica.\n");
        printf("Digite a data no formato dd/mm/aaaa exemplo 21/05/1989.\n");
        printf("Digite a data inicial.\n");
        scanf("%lu/%lu/%lu", &dia_inicial, &mes_inicial, &ano_inicial);
        printf("Digite os dias que serao acrescentados.\n");
        scanf("%lu", &dias_a_somar);

        dia_final = 28;
        mes_final = 12;
        ano_final = 9999999;
    }



    /*Fazer verificacao de entrada de dados*/

    ano = ano_inicial;
    primeiro_dia_do_mes = dia_inicial;



    for(i = ano; i <= ano_final; i++)
    {

        if(i != ano_final)
        {
            mes = 12;
        }
        else
        {
            mes = mes_final;
        }
        for(j = mes_inicial; j <= mes; j++)
        {
            if(j == 1)
            {

                dias_do_mes = 31;
                 /*Condicao para nao ir para o proximo mes.*/
                if (j == mes_final && i == ano_final)
                {
                    j = 13;
                    primeiro_dia_do_mes = 0;
                    dias_do_mes = 0;
                    cont_dias = cont_dias + (dia_final - dia_inicial);
                }
                else
                {
                    if (cont_dias == 0)
                    {
                        primeiro_dia_do_mes = dia_inicial;
                    }
                    else
                    {
                        primeiro_dia_do_mes = 0;
                    }
                }

            }
            else
            {
                if(j == 2)
                {
                    //Verificar o o ano eh bissexto.
                    if ((i % 4 == 0) && (i % 100 != 0) || (i % 400 == 0))
                    {
                        dias_do_mes = 29;
                    }
                    else
                    {
                        dias_do_mes = 28;
                    }

                    /*Condicao para nao ir para o proximo mes.*/
                    if (j == mes_final && i == ano_final)
                    {
                        j = 13;
                        primeiro_dia_do_mes = 0;
                        dias_do_mes = 0;
                        cont_dias = cont_dias + (dia_final - dia_inicial);
                    }
                    else
                    {
                        if (cont_dias == 0)
                        {
                            primeiro_dia_do_mes = dia_inicial;
                        }
                        else
                        {
                            primeiro_dia_do_mes = 0;
                        }
                    }
                }
                else
                {
                    if(j == 3)
                    {

                        dias_do_mes = 31;
                        /*Condicao para nao ir para o proximo mes.*/
                        if (j == mes_final && i == ano_final)
                        {
                            j = 13;
                            primeiro_dia_do_mes = 0;
                            dias_do_mes = 0;
                            cont_dias = cont_dias + (dia_final - dia_inicial);
                        }
                        else
                        {
                            if (cont_dias == 0)
                            {
                                primeiro_dia_do_mes = dia_inicial;
                            }
                            else
                            {
                                primeiro_dia_do_mes = 0;
                            }
                        }
                    }
                    else
                    {
                        if(j == 4)
                        {

                            dias_do_mes = 30;
                             /*Condicao para nao ir para o proximo mes.*/
                            if (j == mes_final && i == ano_final)
                            {
                                j = 13;
                                primeiro_dia_do_mes = 0;
                                dias_do_mes = 0;
                                cont_dias = cont_dias + (dia_final - dia_inicial);
                            }
                            else
                            {
                                if (cont_dias == 0)
                                {
                                    primeiro_dia_do_mes = dia_inicial;
                                }
                                else
                                {
                                    if (cont_dias == 0)
                                    {
                                        primeiro_dia_do_mes = dia_inicial;
                                    }
                                    else
                                    {
                                        primeiro_dia_do_mes = 0;
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (j == 5)
                            {

                                dias_do_mes = 31;
                                 /*Condicao para nao ir para o proximo mes.*/
                                if (j == mes_final && i == ano_final)
                                {
                                    j = 13;
                                    primeiro_dia_do_mes = 0;
                                    dias_do_mes = 0;
                                    cont_dias = cont_dias + (dia_final - dia_inicial);
                                }
                                else
                                {
                                    if (cont_dias == 0)
                                    {
                                        primeiro_dia_do_mes = dia_inicial;
                                    }
                                    else
                                    {
                                        if (cont_dias == 0)
                                        {
                                            primeiro_dia_do_mes = dia_inicial;
                                        }
                                        else
                                        {
                                            primeiro_dia_do_mes = 0;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                if (j == 6)
                                {

                                    dias_do_mes = 30;
                                     /*Condicao para nao ir para o proximo mes.*/
                                    if (j == mes_final && i == ano_final)
                                    {
                                        j = 13;
                                        primeiro_dia_do_mes = 0;
                                        dias_do_mes = 0;
                                        cont_dias = cont_dias + (dia_final - dia_inicial);
                                    }
                                    else
                                    {
                                        if (cont_dias == 0)
                                        {
                                            primeiro_dia_do_mes = dia_inicial;
                                        }
                                        else
                                        {
                                            if (cont_dias == 0)
                                            {
                                                primeiro_dia_do_mes = dia_inicial;
                                            }
                                            else
                                            {
                                                primeiro_dia_do_mes = 0;
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    if(j == 7)
                                    {

                                        dias_do_mes = 31;
                                         /*Condicao para nao ir para o proximo mes.*/
                                        if (j == mes_final && i == ano_final)
                                        {
                                            j = 13;
                                            primeiro_dia_do_mes = 0;
                                            dias_do_mes = 0;
                                            cont_dias = cont_dias + (dia_final - dia_inicial);
                                        }
                                        else
                                        {
                                            if (cont_dias == 0)
                                            {
                                                primeiro_dia_do_mes = dia_inicial;
                                            }
                                            else
                                            {
                                                if (cont_dias == 0)
                                                {
                                                    primeiro_dia_do_mes = dia_inicial;
                                                }
                                                else
                                                {
                                                    primeiro_dia_do_mes = 0;
                                                }
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if (j == 8)
                                        {

                                            dias_do_mes = 31;
                                             /*Condicao para nao ir para o proximo mes.*/
                                            if (j == mes_final && i == ano_final)
                                            {
                                                j = 13;
                                                primeiro_dia_do_mes = 0;
                                                dias_do_mes = 0;
                                                cont_dias = cont_dias + (dia_final - dia_inicial);
                                            }
                                            else
                                            {
                                                if (cont_dias == 0)
                                                {
                                                    primeiro_dia_do_mes = dia_inicial;
                                                }
                                                else
                                                {
                                                    primeiro_dia_do_mes = 0;
                                                }
                                            }
                                        }
                                        else
                                        {
                                            if (j == 9)
                                            {

                                                dias_do_mes = 30;
                                                 /*Condicao para nao ir para o proximo mes.*/
                                                if (j == mes_final && i == ano_final)
                                                {
                                                    j = 13;
                                                    primeiro_dia_do_mes = 0;
                                                    dias_do_mes = 0;
                                                    cont_dias = cont_dias + (dia_final - dia_inicial);
                                                }
                                                else
                                                {
                                                    if (cont_dias == 0)
                                                    {
                                                        primeiro_dia_do_mes = dia_inicial;
                                                    }
                                                    else
                                                    {
                                                        primeiro_dia_do_mes = 0;
                                                    }
                                                }
                                            }
                                            else
                                            {
                                                if (j == 10)
                                                {

                                                    dias_do_mes = 31;
                                                     /*Condicao para nao ir para o proximo mes.*/
                                                    if (j == mes_final && i == ano_final)
                                                    {
                                                        j = 13;
                                                        primeiro_dia_do_mes = 0;
                                                        dias_do_mes = 0;
                                                        cont_dias = cont_dias + (dia_final - dia_inicial);
                                                    }
                                                    else
                                                    {
                                                        if (cont_dias == 0)
                                                        {
                                                            primeiro_dia_do_mes = dia_inicial;
                                                        }
                                                        else
                                                        {
                                                            primeiro_dia_do_mes = 0;
                                                        }
                                                    }
                                                }
                                                else
                                                {
                                                    if (j == 11)
                                                    {

                                                        dias_do_mes = 30;
                                                         /*Condicao para nao ir para o proximo mes.*/
                                                        if (j == mes_final && i == ano_final)
                                                        {
                                                            j = 13;
                                                            primeiro_dia_do_mes = 0;
                                                            dias_do_mes = 0;
                                                            cont_dias = cont_dias + (dia_final - dia_inicial);
                                                        }
                                                        else
                                                        {
                                                            if (cont_dias == 0)
                                                            {
                                                                primeiro_dia_do_mes = dia_inicial;
                                                            }
                                                            else
                                                            {
                                                                primeiro_dia_do_mes = 0;
                                                            }
                                                        }
                                                    }
                                                    else
                                                    {
                                                        if (j == 12)
                                                        {

                                                            dias_do_mes = 31;
                                                             /*Condicao para nao ir para o proximo mes.*/
                                                            if (j == mes_final && i == ano_final)
                                                            {
                                                                j = 13;
                                                                primeiro_dia_do_mes = 0;
                                                                dias_do_mes = 0;
                                                                cont_dias = cont_dias + (dia_final - dia_inicial);
                                                            }
                                                            else
                                                            {
                                                                if (cont_dias == 0)
                                                                {
                                                                    primeiro_dia_do_mes = dia_inicial;
                                                                }
                                                                else
                                                                {
                                                                    primeiro_dia_do_mes = 0;
                                                                }
                                                            }

                                                            mes_inicial = 1;

                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            for(k = primeiro_dia_do_mes; k < dias_do_mes; k++)
            {
                cont_dias++;
                if (opcao == 2 && (dias_a_somar == cont_dias))
                {
                    dia_final = k + 1;
                    mes_final = j;
                    ano_final = i;

                    k = dias_do_mes + 1;
                    j = 13;
                    i = ano_final + 1;

                }
            }

            dia_inicial = 0;

        }

    }

    if (opcao == 1)
    {
         printf("\nDiferenca em dias = %lu\n" ,cont_dias);
    }
    else
    {
        printf("\nData %02lu/%02lu/%lu\n" ,dia_final, mes_final, ano_final);
    }

    return 0;
}















    void ler_arquivo_gas_txt()
    {
        printf("\nFUNCAO LER_ARQUIVO_GAS_TXT.\n");
        unsigned long i, j,
        unsigned long id, data, dia_inicial, mes_inicial, ano_inicial;
        char local_da_compra[10];


        /*criando a variavel ponteiro para o arquivo.*/
        FILE *file;

        /* "a+"	Abre um arquivo texto para gravacao e leitura. Os dados serao adicionados no fim do arquivo se ele ja existir, ou um novo arquivo sera criado, no caso de arquivo nao existente anteriormente.*/
        file = fopen("gas.txt","a+");

        /*
        if(file == NULL)
        {
            printf("\n\tERRO.\n");
            printf("\n\tArquivo nao pode ser aberto.\n");
            printf("\tO arquivo glass.data e o codigo fonte podem nao estar na mesma pasta.\n");
            exit(0);
        }
        else
        {
            printf("\n\tArquivo aberto com sucesso.\n\tDados copiados na memoria.\n\tArquivo fechado.\n\n");
        }
        */

        /*Preenchendo a matriz com os valores do arquivo.*/
        for(i = 0; i < 1; i++)
        {
            fscanf(file, "ID: %s.\n", &texto);

            printf("\nTEXTO: %s\n", texto);
        }

        /*fechando o arquivo*/
        fclose(file);

    }

