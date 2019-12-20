#include <stdio.h>

int main ()
{
    unsigned long dia_inicial = 0, mes_inicial = 0, ano_inicial = 0, dia_final = 0, mes_final = 0, ano_final = 0, dias_a_somar = 0, opcao = 3;

    //declarando funcoes
    int calculadora_de_datas(unsigned long *pdia_inicial, unsigned long *pmes_inicial, unsigned long *pano_inicial, unsigned long *pdia_final, unsigned long *pmes_final, unsigned long *pano_final, unsigned long *pdias_a_somar, unsigned long *popcao);
    void ler_arquivo_gas_txt();

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
    else if(opcao == 2)
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

    //chamando a funcao que calcula datas
    calculadora_de_datas(&dia_inicial, &mes_inicial, &ano_inicial, &dia_final, &mes_final, &ano_final, &dias_a_somar, &opcao);
    ler_arquivo_gas_txt();


    return 0;
}

int calculadora_de_datas(unsigned long *pdia_inicial, unsigned long *pmes_inicial, unsigned long *pano_inicial, unsigned long *pdia_final, unsigned long *pmes_final, unsigned long *pano_final, unsigned long *pdias_a_somar, unsigned long *popcao)
{
    unsigned long i, j, dias_do_mes, mes_do_ano, dia_da_semana = 0, opcaozero = 0;
    unsigned long ano, mes, primeiro_dia_do_mes, cont_dias = 0, k;
    //variaveis criadas para o calcula do dia da semana.
    //todas elas tem o final _s.
    unsigned long dia_inicial_s, mes_inicial_s, ano_inicial_s, dia_final_s, mes_final_s, ano_final_s, dias_a_somar_s, opcaozero_s;

    // primeiro definir uma funcao que calcula void dia_da_semana();
    /*Fazer verificacao de entrada de dados*/

    ano = *pano_inicial;
    primeiro_dia_do_mes = *pdia_inicial;

    for(i = ano; i <= *pano_final; i++)
    {

        if(i != *pano_final)
        {
            mes = 12;
        }
        else
        {
            mes = *pmes_final;
        }
        for(j = *pmes_inicial; j <= mes; j++)
        {
            if(j == 1)
            {

                dias_do_mes = 31;
                 /*Condicao para nao ir para o proximo mes.*/
                if (j == *pmes_final && i == *pano_final)
                {
                    j = 13;
                    primeiro_dia_do_mes = 0;
                    dias_do_mes = 0;
                    cont_dias = cont_dias + (*pdia_final - *pdia_inicial);
                }
                else
                {
                    if (cont_dias == 0)
                    {
                        primeiro_dia_do_mes = *pdia_inicial;
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
                    if (j == *pmes_final && i == *pano_final)
                    {
                        j = 13;
                        primeiro_dia_do_mes = 0;
                        dias_do_mes = 0;
                        cont_dias = cont_dias + (*pdia_final - *pdia_inicial);
                    }
                    else
                    {
                        if (cont_dias == 0)
                        {
                            primeiro_dia_do_mes = *pdia_inicial;
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
                        if (j == *pmes_final && i == *pano_final)
                        {
                            j = 13;
                            primeiro_dia_do_mes = 0;
                            dias_do_mes = 0;
                            cont_dias = cont_dias + (*pdia_final - *pdia_inicial);
                        }
                        else
                        {
                            if (cont_dias == 0)
                            {
                                primeiro_dia_do_mes = *pdia_inicial;
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
                            if (j == *pmes_final && i == *pano_final)
                            {
                                j = 13;
                                primeiro_dia_do_mes = 0;
                                dias_do_mes = 0;
                                cont_dias = cont_dias + (*pdia_final - *pdia_inicial);
                            }
                            else
                            {
                                if (cont_dias == 0)
                                {
                                    primeiro_dia_do_mes = *pdia_inicial;
                                }
                                else
                                {
                                    if (cont_dias == 0)
                                    {
                                        primeiro_dia_do_mes = *pdia_inicial;
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
                                if (j == *pmes_final && i == *pano_final)
                                {
                                    j = 13;
                                    primeiro_dia_do_mes = 0;
                                    dias_do_mes = 0;
                                    cont_dias = cont_dias + (*pdia_final - *pdia_inicial);
                                }
                                else
                                {
                                    if (cont_dias == 0)
                                    {
                                        primeiro_dia_do_mes = *pdia_inicial;
                                    }
                                    else
                                    {
                                        if (cont_dias == 0)
                                        {
                                            primeiro_dia_do_mes = *pdia_inicial;
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
                                    if (j == *pmes_final && i == *pano_final)
                                    {
                                        j = 13;
                                        primeiro_dia_do_mes = 0;
                                        dias_do_mes = 0;
                                        cont_dias = cont_dias + (*pdia_final - *pdia_inicial);
                                    }
                                    else
                                    {
                                        if (cont_dias == 0)
                                        {
                                            primeiro_dia_do_mes = *pdia_inicial;
                                        }
                                        else
                                        {
                                            if (cont_dias == 0)
                                            {
                                                primeiro_dia_do_mes = *pdia_inicial;
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
                                        if (j == *pmes_final && i == *pano_final)
                                        {
                                            j = 13;
                                            primeiro_dia_do_mes = 0;
                                            dias_do_mes = 0;
                                            cont_dias = cont_dias + (*pdia_final - *pdia_inicial);
                                        }
                                        else
                                        {
                                            if (cont_dias == 0)
                                            {
                                                primeiro_dia_do_mes = *pdia_inicial;
                                            }
                                            else
                                            {
                                                if (cont_dias == 0)
                                                {
                                                    primeiro_dia_do_mes = *pdia_inicial;
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
                                            if (j == *pmes_final && i == *pano_final)
                                            {
                                                j = 13;
                                                primeiro_dia_do_mes = 0;
                                                dias_do_mes = 0;
                                                cont_dias = cont_dias + (*pdia_final - *pdia_inicial);
                                            }
                                            else
                                            {
                                                if (cont_dias == 0)
                                                {
                                                    primeiro_dia_do_mes = *pdia_inicial;
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
                                                if (j == *pmes_final && i == *pano_final)
                                                {
                                                    j = 13;
                                                    primeiro_dia_do_mes = 0;
                                                    dias_do_mes = 0;
                                                    cont_dias = cont_dias + (*pdia_final - *pdia_inicial);
                                                }
                                                else
                                                {
                                                    if (cont_dias == 0)
                                                    {
                                                        primeiro_dia_do_mes = *pdia_inicial;
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
                                                    if (j == *pmes_final && i == *pano_final)
                                                    {
                                                        j = 13;
                                                        primeiro_dia_do_mes = 0;
                                                        dias_do_mes = 0;
                                                        cont_dias = cont_dias + (*pdia_final - *pdia_inicial);
                                                    }
                                                    else
                                                    {
                                                        if (cont_dias == 0)
                                                        {
                                                            primeiro_dia_do_mes = *pdia_inicial;
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
                                                        if (j == *pmes_final && i == *pano_final)
                                                        {
                                                            j = 13;
                                                            primeiro_dia_do_mes = 0;
                                                            dias_do_mes = 0;
                                                            cont_dias = cont_dias + (*pdia_final - *pdia_inicial);
                                                        }
                                                        else
                                                        {
                                                            if (cont_dias == 0)
                                                            {
                                                                primeiro_dia_do_mes = *pdia_inicial;
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
                                                            if (j == *pmes_final && i == *pano_final)
                                                            {
                                                                j = 13;
                                                                primeiro_dia_do_mes = 0;
                                                                dias_do_mes = 0;
                                                                cont_dias = cont_dias + (*pdia_final - *pdia_inicial);
                                                            }
                                                            else
                                                            {
                                                                if (cont_dias == 0)
                                                                {
                                                                    primeiro_dia_do_mes = *pdia_inicial;
                                                                }
                                                                else
                                                                {
                                                                    primeiro_dia_do_mes = 0;
                                                                }
                                                            }

                                                            *pmes_inicial = 1;

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
                if (*popcao == 2 && (*pdias_a_somar == cont_dias))
                {
                    *pdia_final = k + 1;
                    *pmes_final = j;
                    *pano_final = i;

                    k = dias_do_mes + 1;
                    j = 13;
                    i = *pano_final + 1;

                }
            }

            *pdia_inicial = 0;

        }

    }



    //imprindo resultado
    if (*popcao == 0)
    {
        return (int)cont_dias;
    }
    else if (*popcao == 1)
    {
         printf("\nDiferenca em dias = %lu\n" ,cont_dias);
         return 0;
    }
    else if (*popcao == 2)
    {
        //calculando dia da semana.
        //o dia da semana da data 21/05/1905 eh domingo.
        //vamos chamar a funcao calculadora_de_datas e calcular a diferenca em dias ate a data inicial.
        //o resto da divisao entre os dias e 7 determinarao o dia da semana.
        //vamos passar outras variaveis para funcao afim de nao alterar o valor original.
        //o final _s identifica as variaveis que foram alteradas para o calculo do dia da semana.
        dia_final_s = *pdia_final;
        mes_final_s = *pmes_final;
        ano_final_s = *pano_final;
        dia_inicial_s = 21;
        mes_inicial_s = 5;
        ano_inicial_s = 1905;
        dias_a_somar_s = 0;

        dia_da_semana = (calculadora_de_datas(&dia_inicial_s, &mes_inicial_s, &ano_inicial_s, &dia_final_s, &mes_final_s, &ano_final_s, &dias_a_somar_s, &opcaozero_s) % 7);

        /*
        Na data Domingo 21/05/1905
        Pegamos o dia da data e fazemos o seguinte calculo:
        21 % 7 = 0 (resto da divisao entre 21 e 7 eh igual a 0)
        Entao toda vez que o dia % 7 = 0 sera domingo.
        Se dia % 7 = 1 sera Segunda-feira.
        Se dia % 7 = 2 sera Terca_feira.
        Se dia % 7 = 6 sera Sabado.
        Assim por diante.
        Isto vale para qualquer data.
        */

        //dia da semana
        if(dia_da_semana == 0)
        {
            printf("\nDomingo ");
        }
        else if(dia_da_semana == 1)
        {
            printf("\nSegunda-feira ");
        }
        else if(dia_da_semana == 2)
        {
            printf("\nTerca-feira ");
        }
        else if(dia_da_semana == 3)
        {
            printf("\nQuarta-feira ");
        }
        else if(dia_da_semana == 4)
        {
            printf("\nQuinta-feira ");
        }
        else if(dia_da_semana == 5)
        {
            printf("\nSexta-feira ");
        }
        else if(dia_da_semana == 6)
        {
            printf("\nSabado ");
        }


        printf(" %02lu/%02lu/%lu\n" ,*pdia_final, *pmes_final, *pano_final);
        return 0;
    }

}















    void ler_arquivo_gas_txt()
    {
        printf("\nFUNCAO LER_ARQUIVO_GAS_TXT.\n");
        unsigned long i, j;
        unsigned long id, data, dia_inicial, mes_inicial, ano_inicial,texto;
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
            fscanf(file, "ID: %s.\n", &local_da_compra);

            printf("\nTEXTO: %s\n", local_da_compra);
        }

        /*fechando o arquivo*/
        fclose(file);

    }

