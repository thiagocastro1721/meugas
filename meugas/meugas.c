#include <stdio.h>
#include <math.h>
int main ()
{
    printf("*******************************************************************************\n");
    printf("                         MEU GAS.\n");
    printf("*******************************************************************************\n");

    //entradas
    double peso_total_inicial = 0, peso_atual = 0, tara_botijao = 0, tara_registro = 0, taras = 0;

    int repetir = 1;
    signed long dia_inicial = 0, mes_inicial = 0, ano_inicial = 0, dia_final = 0, mes_final = 0, ano_final = 0, dias_a_calcular = 0, opcao = -1;

    //saidas
    double peso_gas_inicial = 0, peso_gas_atual = 0, percentual_gas_atual = 0;
    double consumo_medio_diario, consumo_medio_diario_percentual;
    double dias_remanecentes;
    double matriz_gas[20][14];

    //parametros
    double id = 0;
    double medicao = 0;
    double dia_inicial_de_consumo = 0;
    double mes_inicial_de_consumo = 0;
    double ano_inicial_de_consumo = 0;
    double peso_inicial_total = 0;
    double peso_inicial_do_gas = 0;
    double tara_do_botijao = 0;
    double tara_do_registro = 0;
    double dia_do_termino = 0;
    double mes_do_termino = 0;
    double ano_do_termino = 0;
    double duracao_final_em_dias = 0;
    double zero1 = 0;
    double zero2 = 0;

    int i, j;
    //duracao_atual = diferenca em dias entre a data inicial de utilizacao e a data atual de medicao.
    int duracao_atual;
    int dia_da_semana;

    //previsao de termino
    int dia_previsto, mes_previsto, ano_previsto;

    int salvar = 2;

    /*declarando funcoes*/
    int captura_e_valida_dados_do_teclado(signed long *pdia_inicial, signed long *pmes_inicial, signed long *pano_inicial, signed long *pdia_final, signed long *pmes_final, signed long *pano_final, signed long *pdias_a_calcular, signed long *popcao);
    int validar_datas(signed long *pdia_inicial, signed long *pmes_inicial, signed long *pano_inicial, signed long *pdia_final, signed long *pmes_final, signed long *pano_final, signed long *pdias_a_calcular, signed long *popcao);
    int calculadora_de_datas(signed long *pdia_inicial, signed long *pmes_inicial, signed long *pano_inicial, signed long *pdia_final, signed long *pmes_final, signed long *pano_final, signed long *pdias_a_calcular, signed long *popcao);
    void ler_arquivo_gas_data(double r[20][14]);
    void gravar_dados_gas_data(double w[20][14]);

    ler_arquivo_gas_data(matriz_gas);

        //impriminto
        printf("\nImprimindo os valores do arquivo\n");
        for(i = 0; i < 20; i++)
        {
            printf("\n");
            for(j = 0; j < 14; j++)
            {
                 printf("%.0f ", matriz_gas[i][j]);
            }
        }

    if(matriz_gas[0][0] == 0)
    {
        printf("\nmatriz_gas[0][0] == 0. Iniciando captura de dados para o gas 1.\n");

        id++;
        medicao++;


        while(repetir == 1)
    {

        printf("\nDigite o peso total inicial do conjunto em Kg. (Botijao + Gas + Registro).\n");
        scanf("%lf", &peso_total_inicial);

        printf("Digite o peso total atual do conjunto em Kg. (Botijao + Gas + Registro).\n");
        scanf("%lf", &peso_atual);

        printf("Digite a tara do botijao em Kg.\n");
        scanf("%lf", &tara_botijao);

        printf("Digite a tara do registro em Kg.\n");
        scanf("%lf", &tara_registro);


/*
        peso_total_inicial = 28.4;
        peso_atual = 15.4;
        tara_botijao = 15.1;
        tara_registro = 0.3;
*/


        peso_gas_inicial = peso_total_inicial - tara_botijao - tara_registro;
        taras = tara_botijao + tara_registro;
        peso_gas_atual = peso_atual - taras;
        percentual_gas_atual = (peso_gas_atual / peso_gas_inicial) * 100;

        //Erro. Peso atual do gas eh negativo

        while(peso_gas_atual < 0)
        {
            printf("\npeso atual do gas = %f\n", peso_gas_atual);

            printf("\nErro. O peso atual do gas nao pode ser negativo.\nVerifique as entradas e digite novamente.\n");

            printf("\nDigite o peso total inicial do conjunto em Kg. (Botijao + Gas + Registro).\n");
            scanf("%lf", &peso_total_inicial);

            printf("Digite o peso TOTAL atual do conjunto em Kg. (Botijao + Gas + Registro).\n");
            scanf("%lf", &peso_atual);

            printf("Digite a tara do botijao em Kg.\n");
            scanf("%lf", &tara_botijao);

            printf("Digite a tara do registro em Kg.\n");
            scanf("%lf", &tara_registro);

            peso_gas_inicial = peso_total_inicial - tara_botijao - tara_registro;
            peso_gas_atual = (peso_atual - (tara_botijao + tara_registro));
            percentual_gas_atual = (peso_gas_atual / peso_gas_inicial) * 100;

            }

            printf("\n");
            printf("*******************************************************************************\n");//linha inicial

            printf("Id ----------------------- = %.0f\n", id);
            printf("Medicao ------------------ = %.0f\n", medicao);

            duracao_atual = captura_e_valida_dados_do_teclado(&dia_inicial, &mes_inicial, &ano_inicial, &dia_final, &mes_final, &ano_final, &dias_a_calcular, &opcao);



            //signed long *pdias_a_calcular = 0;
            //signed long *popcao = 0;

            //duracao_atual = calculadora_de_datas(&*pdia_inicial, &*pmes_inicial, &*pano_inicial, &*pdia_final, &*pmes_final, &*pano_final, &*pdias_a_calcular, &*popcao);

            consumo_medio_diario = (peso_gas_inicial - peso_gas_atual) / duracao_atual;
            dias_remanecentes = peso_gas_atual / consumo_medio_diario;



            printf("Data inicial de consumo -- = %02li/%02li/%li\n", dia_inicial, mes_inicial, ano_inicial);// dia perdido
            printf("Peso inicial do conjunto - = %.2f Kg\n", peso_total_inicial);
            printf("Peso atual do conjunto --- = %.2f Kg\n", peso_atual);
            printf("Peso inicial do gas ------ = %.2f Kg\n", peso_gas_inicial);
            printf("Tara do botijao ---------- = %.2f Kg\n", tara_botijao);
            printf("Tara do registro --------- = %.2f Kg\n", tara_registro);
            printf("Peso atual do gas -------- = %.2f Kg\n", peso_gas_atual);
            printf("Consumo medio diario ----- = %.3f kg/dia \n", consumo_medio_diario);
            printf("Percentual atual --------- = %.2f %%\n", percentual_gas_atual, peso_gas_atual, peso_gas_inicial);
            printf("Dias restantes ----------- = %d Dias\n", (int)dias_remanecentes);
            printf("Previsao de termino ------ = ");
            opcao = 2;
            dias_a_calcular = dias_remanecentes;
            dia_da_semana = captura_e_valida_dados_do_teclado(&dia_inicial, &mes_inicial, &ano_inicial, &dia_final, &mes_final, &ano_final, &dias_a_calcular, &opcao);

            //Não será mostrada esta variavel.
            //printf("Dia da semana ------------ = %d\n", dia_da_semana);

            if(peso_gas_atual == 0)
            {
                printf("Data de termino ---------- = ");
                //dia da semana
                if(dia_da_semana == 0)
                {
                    printf("Segunda-feira ");
                }
                else if(dia_da_semana == 1)
                {
                    printf("Terca-feira ");
                }
                else if(dia_da_semana == 2)
                {
                    printf("Quarta-feira ");
                }
                else if(dia_da_semana == 3)
                {
                    printf("Quinta-feira ");
                }
                else if(dia_da_semana == 4)
                {
                    printf("Sexta-feira ");
                }
                else if(dia_da_semana == 5)
                {
                    printf("Sabado ");
                }
                else if(dia_da_semana == 6)
                {
                    printf("Domingo ");
                }

                printf(" %02li/%02li/%li\n", dia_final, mes_final, ano_final);
                printf("Duracao final ------------ = %li Dias\n", duracao_atual);
            }
            printf("*******************************************************************************\n");//linha final

            printf("\nDeseja salvar os dados no arquivo gas.data? 1(sim) ou 0(nao).\n");
            scanf("%d", &salvar);
            if(salvar == 1)
            {
                printf("\nVerifique se os dados estao corretos.\n");
                printf("\nTem certeza que DESEJA SALVAR os dados no arquivo gas.data? 1(sim) ou 0(nao).\n");
                scanf("%d", &salvar);
                if(salvar == 1)
                {
                    printf("\nDados salvos em gas.data.\nSempre faca backup.");
                }
                else if(salvar == 0)
                {
                    printf("\nOperacao cancelada.\n");
                }
                else
                {
                    printf("\nOpcao invalida.\nOperacao cancelada.");
                }
            }
            else if(salvar == 0)
            {
                printf("\nOperacao cancelada.\n");
            }
            else
            {
                printf("\nOpcao invalida.\nOperacao cancelada.");
            }

            printf("\nDeseja realizar outro calculo? ""1""(sim) ou ""0""(nao).\n");
            scanf("%i", &repetir);
            opcao = -1;
        }
    }
    else
    {
        printf("\nmatriz_gas[0][0] =! 0. Mostrando dados da ultima linha.\n");

        id = matriz_gas[19][0];
        dia_inicial_de_consumo = matriz_gas[19][1];
        mes_inicial_de_consumo = matriz_gas[19][2];
        ano_inicial_de_consumo = matriz_gas[19][3];
        peso_inicial_total = matriz_gas[19][4];
        peso_inicial_do_gas = matriz_gas[19][5];
        tara_do_botijao = matriz_gas[19][6];
        tara_do_registro = matriz_gas[19][7];
        dia_do_termino = matriz_gas[19][8];
        mes_do_termino = matriz_gas[19][9];
        ano_do_termino = matriz_gas[19][10];
        duracao_final_em_dias = matriz_gas[19][11];

        printf("\nid = %.0f\n", id);
        printf("\ndia_inicial_de_consumo = %.0f\n", dia_inicial_de_consumo);
        printf("\nmes_inicial_de_consumo = %.0f\n", mes_inicial_de_consumo);
        printf("\nano_inicial_de_consumo = %.0f\n", ano_inicial_de_consumo);
        printf("\npeso_inicial_total = %.1f\n", peso_inicial_total);
        printf("\npeso_inicial_do_gas = %.1f\n", peso_inicial_do_gas);
        printf("\ntara_do_botijao = %.1f\n", tara_do_botijao);
        printf("\ntara_do_registro = %.1f\n", tara_do_registro);
        printf("\ndia_do_termino = %.0f\n", dia_do_termino);
        printf("\nmes_do_termino = %.0f\n", mes_do_termino);
        printf("\nano_do_termino = %.0f\n", ano_do_termino);
        printf("\nduracao_final_em_dias = %.0f\n", duracao_final_em_dias);
    }

    return 0;
}

int captura_e_valida_dados_do_teclado(signed long *pdia_inicial, signed long *pmes_inicial, signed long *pano_inicial, signed long *pdia_final, signed long *pmes_final, signed long *pano_final, signed long *pdias_a_calcular, signed long *popcao)
{
    int cont_dias;
    signed long meses_a_calcular, anos_a_calcular;
    //variaveis criadas para o calculo parcial da diferenca em dias na opcao 2.
    signed long op2_mes_final, op2_ano_final, op3_mes_final,op3_ano_final, guarda_dias_calcular;

    /*Declarando funcao validar_datas*/
    int validar_datas(signed long *pdia_inicial, signed long *pmes_inicial, signed long *pano_inicial, signed long *pdia_final, signed long *pmes_final, signed long *pano_final, signed long *pdias_a_calcular, signed long *popcao);

    /*Declarando variaveis temporarias para a troca de datas*/
    signed long temp_dia_inicial, temp_mes_inicial, temp_ano_inicial;

    /*declarando a funcao calculadora de datas*/
    int calculadora_de_datas(signed long *pdia_inicial, signed long *pmes_inicial, signed long *pano_inicial, signed long *pdia_final, signed long *pmes_final, signed long *pano_final, signed long *pdias_a_calcular, signed long *popcao);

    /*if para pedir a opcao so 1 vez*/
    if(*popcao == -1)
    {
        *popcao = 1;
    }

    if(*popcao == 1)
    {
        /*
        printf("Digite a data inicial de utilizacao. dd/mm/aaaa\n");
        scanf("%d/%d/%d", &*pdia_inicial, &*pmes_inicial, &*pano_inicial);

        printf("Digite a data  de medicao. dd/mm/aaaa\n");
        scanf("%d/%d/%d", &*pdia_final, &*pmes_final, &*pano_final);
        */
        *pdia_inicial = 8;
        *pmes_inicial = 1;
        *pano_inicial = 2020;
        *pdia_final = 11;
        *pmes_final = 4;
        *pano_final = 2020;
        /*caso a primeira data seja maior que a segunda data*/
        while((*pano_inicial > *pano_final) || ((*pano_inicial == *pano_final) && (*pmes_inicial > *pmes_final)) || ((*pano_inicial == *pano_final) && (*pmes_inicial == *pmes_final) && (*pdia_inicial > *pdia_final)))
        {
            printf("ERRO.\nData de medicao anterior a data inicial de utilizacao.\n");

            printf("Digite a data inicial de utilizacao. dd/mm/aaaa\n");
            scanf("%d/%d/%d", &*pdia_inicial, &*pmes_inicial, &*pano_inicial);

            printf("Digite a data  de medicao. dd/mm/aaaa\n");
            scanf("%d/%d/%d", &*pdia_final, &*pmes_final, &*pano_final);
        }

         cont_dias = validar_datas(&*pdia_inicial, &*pmes_inicial, &*pano_inicial, &*pdia_final, &*pmes_final, &*pano_final, &*pdias_a_calcular, &*popcao);

    }
    else if(*popcao == 2)
    {
        *pdia_inicial = *pdia_final;
        *pmes_inicial = *pmes_final;
        *pano_inicial = *pano_final;

        guarda_dias_calcular = *pdias_a_calcular;

        //recuperar o valor original de *pdias_a_calcular.
        *pdias_a_calcular = guarda_dias_calcular;

        *pdia_final = 31;
        *pmes_final = 12;
        *pano_final = 9999999;


        //validar data e calcular a data inicial mais os dias.
        cont_dias = validar_datas(&*pdia_inicial, &*pmes_inicial, &*pano_inicial, &*pdia_final, &*pmes_final, &*pano_final, &*pdias_a_calcular, &*popcao);
    }

    return cont_dias;
}

 int validar_datas(signed long *pdia_inicial, signed long *pmes_inicial, signed long *pano_inicial, signed long *pdia_final, signed long *pmes_final, signed long *pano_final, signed long *pdias_a_calcular, signed long *popcao)
 {
        int erro = 0;
        int cont_dias;

        /*declarando a funcao calculadora_de_datas*/
        int calculadora_de_datas(signed long *pdia_inicial, signed long *pmes_inicial, signed long *pano_inicial, signed long *pdia_final, signed long *pmes_final, signed long *pano_final, signed long *pdias_a_calcular, signed long *popcao);

        /*declarando a funcao capturar dados_do_teclado*/
        int captura_e_valida_dados_do_teclado(signed long *pdia_inicial, signed long *pmes_inicial, signed long *pano_inicial, signed long *pdia_final, signed long *pmes_final, signed long *pano_final, signed long *pdias_a_calcular, signed long *popcao);

        if(*popcao == 1)
        {
             //Os anos nao podem ser negativos e nem serem maiores que 9999999.
            if((*pano_inicial < 1) || (*pano_inicial > 9999999) || (*pano_final < 1) || (*pano_final > 9999999))
            {
                //printf("\nvalores da funcao %li, %li, %li, %li, %li, %li, %li, %li, \n", *pdia_inicial, *pmes_inicial, *pano_inicial, *pdia_final, *pmes_final, *pano_final, *pdias_a_calcular, *popcao);
                printf("\nData invalida. Verifique os anos.\n\n");
                erro++;
            }

            //Os meses nao podem ser negativos e nem maiores que 12.
            if((*pmes_inicial < 1) || (*pmes_inicial > 12) || (*pmes_final < 1) || (*pmes_final > 12))
            {
                printf("\nData invalida. Verifique os meses.\n\n");
                erro++;
            }

             //Os dias nao podem ser negativos.
            if((*pdia_inicial < 1) || (*pdia_final < 1))
            {
                printf("\nData invalida. Verifique os dias.\nOs dias devem ser numeros inteiros maiores que 0.\n\n");
                erro++;
            }

            //Se o ano inicial for bissexto, entao o mes de fevereiro tera 29 dias. Se nao, tera 28 dias.
            if((*pano_inicial%4 == 0) && (*pano_inicial%100 != 0) || (*pano_inicial%400 == 0))
            {
                if((*pdia_inicial > 29) && (*pmes_inicial == 2))
                {
                    //printf("\n*pdia_inicial = %li, *pdia_final = %li\n",*pdia_inicial, *pdia_final);
                    printf("\nData invalida. Verifique os dias. O ano %li eh bissexto, entao fevereiro tem 29 dias.\n\n", *pano_inicial);
                    erro++;
                }
            }
            else
            {
                if((*pdia_inicial > 28) && (*pmes_inicial == 2))
                {
                    //printf("\n*pdia_inicial = %li, *pdia_final = %li\n",*pdia_inicial, *pdia_final);
                    printf("\nData invalida. Verifique os dias. O ano %li nao eh bissexto, entao fevereiro tem 28 dias.\n\n", *pano_inicial);
                    erro++;
                }
            }

            //Se o ano final for bissexto, entao o mes de fevereiro tera 29 dias. Se nao, tera 28 dias.
            if((*pano_final%4 == 0) && (*pano_final%100 != 0) || (*pano_final%400 == 0))
            {
                if((*pdia_final > 29) && (*pmes_final == 2))
                {
                    //printf("\n*pdia_inicial = %li, *pdia_final = %li\n",*pdia_inicial, *pdia_final);
                    printf("\nData invalida. Verifique os dias. O ano %li eh bissexto, entao fevereiro tem 29 dias.\n\n", *pano_final);
                    erro++;
                }
            }
            else
            {
                if((*pdia_final > 28) && (*pmes_final == 2))
                {
                    //printf("\n*pdia_inicial = %li, *pdia_final = %li\n",*pdia_inicial, *pdia_final);
                    printf("\nData invalida. Verifique os dias. O ano %li nao eh bissexto, entao fevereiro tem 28 dias.\n\n", *pano_final);
                    erro++;
                }
            }

             //Se o mes for abril, ou junho, ou setembro, ou novembro, entao o mes tera 30 dias. Se nao, tera 31 dias.
            if((*pmes_inicial == 4) || (*pmes_inicial == 6) || (*pmes_inicial == 9) || (*pmes_inicial == 11))
            {
                if(*pdia_inicial > 30)
                {
                    printf("\nData invalida. Verifique os dias.\nOs meses de abril, junho, setembro e novembro sao de 30 dias.\n\n\n");
                    erro++;
                }
            }
            else if((*pmes_final == 4) || (*pmes_final == 6) || (*pmes_final == 9) || (*pmes_final == 11))
            {
                if(*pdia_final > 30)
                {
                    printf("\nData invalida. Verifique os dias.\nOs meses de abril, junho, setembro e novembro sao de 30 dias.\n\n\n");
                    erro++;
                }
            }
            else
            {
                if((*pdia_inicial > 31) || (*pdia_final > 31))
                {
                    printf("\nData invalida. Verifique os dias.\nOs meses de janeiro, marco, maio, julho, agosto, outubro e dezembro\nsao de 31 dias.\n\n\n");
                    erro++;
                }
            }
        }
        else if(*popcao == 2)
        {
             //Os anos nao podem ser negativos e nem serem maiores que 9999999.
            if((*pano_inicial < 1) || (*pano_inicial > 9999999))
            {
                //printf("\nvalores da funcao %li, %li, %li, %li, %li, %li, %li, %li, \n", *pdia_inicial, *pmes_inicial, *pano_inicial, *pdia_final, *pmes_final, *pano_final, *pdias_a_calcular, *popcao);
                printf("\nData invalida. Verifique os anos.\n\n");
                erro++;
            }

            //Os meses nao podem ser negativos e nem maiores que 12.
            if((*pmes_inicial < 1) || (*pmes_inicial > 12))
            {
                printf("\nData invalida. Verifique os meses.\n\n");
                erro++;
            }

            //Os dias nao podem ser negativos.
            if(*pdia_inicial < 1)
            {
                printf("\nData invalida. Verifique os dias.\nOs dias devem ser numeros inteiros maiores que 0.\n\n");
                erro++;
            }

            //Se o ano inicial for bissexto, entao o mes de fevereiro tera 29 dias. Se nao, tera 28 dias.
            if((*pano_inicial%4 == 0) && (*pano_inicial%100 != 0) || (*pano_inicial%400 == 0))
            {
                if((*pdia_inicial > 29) && (*pmes_inicial == 2))
                {
                    //printf("\n*pdia_inicial = %li, *pdia_final = %li\n",*pdia_inicial, *pdia_final);
                    printf("\nData invalida. Verifique os dias. O ano %li eh bissexto, entao fevereiro tem 29 dias.\n\n", *pano_inicial);
                    erro++;
                }
            }
            else
            {
                if((*pdia_inicial > 28) && (*pmes_inicial == 2))
                {
                    //printf("\n*pdia_inicial = %li, *pdia_final = %li\n",*pdia_inicial, *pdia_final);
                    printf("\nData invalida. Verifique os dias. O ano %li nao eh bissexto, entao fevereiro tem 28 dias.\n\n", *pano_inicial);
                    erro++;
                }
            }


             //Se o mes for abril, ou junho, ou setembro, ou novembro, entao o mes tera 30 dias. Se nao, tera 31 dias.
            if((*pmes_inicial == 4) || (*pmes_inicial == 6) || (*pmes_inicial == 9) || (*pmes_inicial == 11))
            {
                if(*pdia_inicial > 30)
                {
                    printf("\nData invalida. Verifique os dias.\nOs meses de abril, junho, setembro e novembro sao de 30 dias.\n\n\n");
                    erro++;
                }
            }
            else if((*pmes_final == 4) || (*pmes_final == 6) || (*pmes_final == 9) || (*pmes_final == 11))
            {
                if(*pdia_final > 30)
                {
                    printf("\nData invalida. Verifique os dias.\nOs meses de abril, junho, setembro e novembro sao de 30 dias.\n\n\n");
                    erro++;
                }
            }
            else
            {
                if((*pdia_inicial > 31) || (*pdia_final > 31))
                {
                    printf("\nData invalida. Verifique os dias.\nOs meses de janeiro, marco, maio, julho, agosto, outubro e dezembro\nsao de 31 dias.\n\n\n");
                    erro++;
                }
            }

                        //Digite apenas numeros inteiros positivos para adicionar ou subtrair dias.
            if(*pdias_a_calcular < 0)
            {
                printf("\nDigite apenas numeros inteiros positivos para adicionar ou subtrair dias, meses ou anos.\n\n");
                erro++;
            }
        }

        //Se nao houver erro, entao chama a funcao calculadora_de_datas. Caso contrario chama novamente a funcao de validacao
        if(erro == 0)
        {
            cont_dias = calculadora_de_datas(&*pdia_inicial, &*pmes_inicial, &*pano_inicial, &*pdia_final, &*pmes_final, &*pano_final, &*pdias_a_calcular, &*popcao);

        }
        else
        {
            captura_e_valida_dados_do_teclado(&*pdia_inicial, &*pmes_inicial, &*pano_inicial, &*pdia_final, &*pmes_final, &*pano_final, &*pdias_a_calcular, &*popcao);
        }

        return cont_dias;
 }

int calculadora_de_datas(signed long *pdia_inicial, signed long *pmes_inicial, signed long *pano_inicial, signed long *pdia_final, signed long *pmes_final, signed long *pano_final, signed long *pdias_a_calcular, signed long *popcao)
{
    signed long i, j, dias_do_mes, dias_do_mes_anterior, dia_da_semana = 0;
    signed long ano, mes, primeiro_dia_do_mes, k;
    double  cont_dias = 0;
    signed long maiores_dias, menores_dias, x_dias;
    signed long quant_anos = 0, guarda_dia_inicial, guarda_mes_inicial, quant_meses = 0, quant_dias = 0, quant_anos_bissextos = 0, quant_semanas = 0;
    signed long dia_inicial_d, mes_inicial_d, ano_inicial_d, dias_a_calcular_d, opcao_d;// opcao para calcular a quant_dias

    //variaveis criadas para o calcula do dia da semana.
    //todas elas tem o final _s.
    signed long dia_inicial_s, mes_inicial_s, ano_inicial_s, dia_final_s, mes_final_s, ano_final_s, dias_a_calcular_s, opcaozero_s = 0;
    signed long dia_inicial_sub, mes_inicial_sub, ano_inicial_sub, dia_final_sub, mes_final_sub, ano_final_sub, dias_a_calcular_sub, opcao_sub = 0;
    signed long dia_inicial_md, mes_inicial_md, ano_inicial_md, dia_final_md, mes_final_md, ano_final_md, dias_a_calcular_md, opcao_md;
    signed long contanobissextos = 0;

    ano = *pano_inicial;
    primeiro_dia_do_mes = *pdia_inicial;

    guarda_dia_inicial = *pdia_inicial;
    guarda_mes_inicial = *pmes_inicial;

    //estrutura for que conta os dias
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
                dias_do_mes_anterior = 31;
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
                    //Verificar se o ano eh bissexto.
                    if ((i % 4 == 0) && (i % 100 != 0) || (i % 400 == 0))
                    {
                        dias_do_mes = 29;
                        dias_do_mes_anterior = 31;
                        quant_anos_bissextos++;
                    }
                    else
                    {
                        dias_do_mes = 28;
                        dias_do_mes_anterior = 31;
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

                        if ((i % 4 == 0) && (i % 100 != 0) || (i % 400 == 0))
                        {
                            dias_do_mes_anterior = 29;
                        }
                        else
                        {
                            dias_do_mes_anterior = 28;
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
                        if(j == 4)
                        {

                            dias_do_mes = 30;
                            dias_do_mes_anterior = 31;

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
                                dias_do_mes_anterior = 30;

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
                                    dias_do_mes_anterior = 31;

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
                                        dias_do_mes_anterior = 30;

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
                                            dias_do_mes_anterior = 31;

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
                                                dias_do_mes_anterior = 31;

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
                                                    dias_do_mes_anterior = 30;

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
                                                        dias_do_mes_anterior = 31;

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
                                                            dias_do_mes_anterior = 30;

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
                if (*popcao == 2 && (*pdias_a_calcular == cont_dias))
                {
                    *pdia_final = k;
                    *pmes_final = j;
                    *pano_final = i;

                    k = dias_do_mes + 2;
                    j = 13;
                    i = *pano_final + 1;

                }
                cont_dias++;
            }

            *pdia_inicial = 0;
        }
    }

    //imprindo resultado
    if (*popcao == 0)
    {
        *pdia_inicial = guarda_dia_inicial;
        return (int)cont_dias;
    }
    else if (*popcao == 1)
    {
        //ANOS

        //calculo da diferenca entre duas datas
        //exemplo: data inicial 21/05/1989 e data final 30/01/2020

        //calculo dos anos de diferenca

        if(*pmes_final < guarda_mes_inicial)
        {
            quant_anos = (*pano_final - *pano_inicial) - 1;
            //quant_anos = (2020 - 1989) - 1 = 30
        }
        else if(*pmes_final == guarda_mes_inicial)
        {
            if((guarda_dia_inicial == 29 && *pdia_final == 28) && (guarda_mes_inicial == *pmes_final) && (*pmes_final == 2))
            {
                quant_anos = *pano_final - *pano_inicial;
            }
            else if(*pdia_final < guarda_dia_inicial)
            {
                quant_anos = (*pano_final - *pano_inicial) - 1;
            }
            else if(*pdia_final == guarda_dia_inicial)
            {
                quant_anos = *pano_final - *pano_inicial;
            }
            else if(*pdia_final > guarda_dia_inicial)
            {
                quant_anos = *pano_final - *pano_inicial;
            }
        }
        else if (*pmes_final > guarda_mes_inicial)
        {
            quant_anos = *pano_final - *pano_inicial;
        }
        //concluimos o calculo dos anos
        //por enquanto sabemos que a diferenca em anos eh 30

        dia_inicial_d = guarda_dia_inicial;
        //dia_inicial_d = 21
        mes_inicial_d = guarda_mes_inicial;
        //mes_inicial_d = 05 + 08 = 13
        ano_inicial_d = *pano_inicial + quant_anos;

        //verificacao do dia 29/02 antes de somar os meses
        if(guarda_dia_inicial == 29 && guarda_mes_inicial == 2)
        {
            //Se o ano nao for bissexto e o dia for 29 e o mes for 2, entao o dia muda o seu valor para 28.
            if((ano_inicial_d % 4 != 0) || (ano_inicial_d % 100 == 0) && (ano_inicial_d % 400 != 0))
            {
                if(dia_inicial_d == 29 && mes_inicial_d == 2)
                {
                    dia_inicial_d = 28;
                }
            }
            else
            {
                if(dia_inicial_d == 28 && mes_inicial_d == 2)
                {
                    dia_inicial_d = 29;
                }
            }
        }

        //MESES

        //calculo dos meses de diferenca
        //21/05/1989 + 30 anos = 21/05/2019
        //agora temos duas datas 21/05/2019 e 30/01/2020
        //vamos calcular a diferenca entre as duas datas
        //por enquanto vamos focar na diferenca em meses
        //lembrando que a diferenca nunca sera maior que 12

        if((guarda_dia_inicial == 29 && *pdia_final == 28) && (guarda_mes_inicial == *pmes_final) && (*pmes_final == 2))
        {
            quant_meses = *pmes_final - guarda_mes_inicial;
        }
        else if(*pdia_final < guarda_dia_inicial)
        {
            quant_meses = (*pmes_final - guarda_mes_inicial) - 1;
        }
        else
        {
            quant_meses = *pmes_final - guarda_mes_inicial;
            //quant_meses = 01 - 05 = -4
        }

        if(quant_meses < 0)
        {
            quant_meses = 12 + quant_meses;
            //quant_meses = 12 + (-4) = 8
        }
        //concluimos o calculo dos meses
        //por enquanto sabemos que a diferenca em meses eh 8

        //DIAS REMANESCENTES

        //21/05/1989 e 30/01/2020
        //21/05/1989 + 30 anos = 21/05/2019
        //21/05/2019 + 8 meses = ?

        //somando os meses

        //preparando variaveis para chamar a funcao calculadora_de_datas afim de calcular os dias remanescentes
        mes_inicial_d = guarda_mes_inicial + quant_meses;
        //mes_inicial_d = 05 + 08 = 13
        ano_inicial_d = *pano_inicial + quant_anos;
        //ano_inicial_d = 1989 + 30 = 2019
        opcao_d = 0;
        //opcao_d = 0 retorna somente a diferenca em dias
        dias_a_calcular_d = 0;
        //para o calculo da diferenca em dias nao e necessario usar esta variavel, entao a mesma tem o seu valor zerado

        if(mes_inicial_d > 12)
        {
            mes_inicial_d = mes_inicial_d % 12;
            //mes_inicial_d = 01
            ano_inicial_d = ano_inicial_d + 1;
            //ano_inicial_d = 2019 + 1 = 2020
        }
        //temos
        //dia_inicial_d = 21
        //mes_inicial_d = 01
        //ano_inicial_d = 2020

        //sabemos agora que 21/05/2019 + 8 meses = 21/01/2020

        //agora e soh chamar a funcao calculadora_de_datas
        //para calcular a diferenca em dias entre as seguintes datas
        //21/01/2020 e 30/01/2020




        //OBTENDO DIAS REMANESCENTES
        quant_dias = (calculadora_de_datas(&dia_inicial_d, &mes_inicial_d, &ano_inicial_d, &*pdia_final, &*pmes_final, &*pano_final, &dias_a_calcular_d, &opcao_d));

        //por enquanto sabemos que os dias remanescentes sao 9
        //quant_dias = 9


        //SEMANAS

        quant_semanas = quant_dias / 7;
        //quant_semanas = 9 / 7 = 1

        //concluimos o calculo das semanas
        //por enquanto sabemos que o numero de semanas eh 1

        //DIAS

        //esta eh a quantidade de dias retirando-se as semanas
        quant_dias = quant_dias % 7;
        //quant_dias = 9 % 7 = 2

        //concluimos o calculo dos dias
        //por enquanto sabemos que o numero de dias eh 2

        //IMPRIMINDO RESULTADOS
        //30 Anos 8 Meses 1 Semana 2 Dias
        //Diferenca em dias = 11211

        printf("Duracao atual ------------ = ");
        if(quant_anos > 0)
        {
            if(quant_anos == 1)
            {
                printf("%li Ano ", quant_anos);
            }
            else
            {
                printf("%li Anos ", quant_anos);
            }
        }
        if(quant_meses > 0)
        {
            if(quant_meses == 1)
            {
                printf("%li Mes ", quant_meses);
            }
            else
            {
                printf("%li Meses ", quant_meses);
            }

        }
        if(quant_semanas > 0)
        {
            if(quant_semanas == 1)
            {
                printf("%li Semana ", quant_semanas);
            }
            else
            {
                printf("%li Semanas ", quant_semanas);
            }
        }
        if(quant_dias > 0)
        {
            if(quant_dias == 1)
            {
                printf("%li Dia ", quant_dias);
            }
            else
            {
                printf("%li Dias ", quant_dias);
            }
        }
        if(cont_dias > 0)
        {
            printf("\nDuracao atual ------------ = %.0lf Dias\n", cont_dias);
        }
        if(quant_anos == 0 && quant_meses == 0 && quant_semanas == 0 && quant_dias == 0 && cont_dias == 0)
        {
            printf("\nDatas iguais.\n\n");
        }

        *pdia_inicial = guarda_dia_inicial;
        return cont_dias;
    }
    else if (*popcao == 2)
    {
        //calculando dia da semana.
        //o dia da semana da data 01/01/0001 eh domingo.
        //vamos chamar a funcao calculadora_de_datas e calcular a diferenca em dias ate a data inicial.
        //o resto da divisao entre os dias e 7 determinarao o dia da semana.
        //vamos passar outras variaveis para funcao afim de nao alterar o valor original.
        //o final _s identifica as variaveis que foram alteradas para o calculo do dia da semana.

        dia_final_s = *pdia_final;
        mes_final_s = *pmes_final;
        ano_final_s = *pano_final;
        dia_inicial_s = 1;
        mes_inicial_s = 1;
        ano_inicial_s = 1;
        dias_a_calcular_s = 0;
        opcaozero_s = 0;

        dia_da_semana = (calculadora_de_datas(&dia_inicial_s, &mes_inicial_s, &ano_inicial_s, &dia_final_s, &mes_final_s, &ano_final_s, &dias_a_calcular_s, &opcaozero_s) % 7);

        /*
        Na data terca-feira 01/01/0001
        Pegamos o dia da data e fazemos o seguinte calculo:
        01 % 7 = 1 (resto da divisao entre 1 e 7 eh igual a 1)
        Entao toda vez que o dia % 7 = 1 sera terca-feira.
        Se dia % 7 = 2 sera quarta-feira.
        Se dia % 7 = 3 sera quinta-feira.
        Se dia % 7 = 6 sera domingo.
        Assim por diante.
        Isto vale para qualquer data.
        */

        //dia da semana
        if(dia_da_semana == 0)
        {
            printf("Segunda-feira ");
        }
        else if(dia_da_semana == 1)
        {
            printf("Terca-feira ");
        }
        else if(dia_da_semana == 2)
        {
            printf("Quarta-feira ");
        }
        else if(dia_da_semana == 3)
        {
            printf("Quinta-feira ");
        }
        else if(dia_da_semana == 4)
        {
            printf("Sexta-feira ");
        }
        else if(dia_da_semana == 5)
        {
            printf("Sabado ");
        }
        else if(dia_da_semana == 6)
        {
            printf("Domingo ");
        }

        //correcao do bug da opcao 3 entrada: 01/12/2020 menos 1 dia. Saida: 00/12/2020.
        if(*pdia_final == 0)
        {
            if(*pdia_final == 0 && *pmes_final == 1)
            {
                *pdia_final = dias_do_mes_anterior;
                *pmes_final = 12;
                *pano_final = *pano_final - 1;
            }
            else
            {
                *pdia_final = dias_do_mes_anterior;
                *pmes_final = *pmes_final - 1;
            }
        }

        printf(" %02li/%02li/%li\n" ,*pdia_final, *pmes_final, *pano_final);

        *pdia_inicial = guarda_dia_inicial;

        return dia_da_semana;//vai retornar para as outras funcoes o valor do dia da semana. A variável con_dias ira receber o valor.
    }

}
void ler_arquivo_gas_data(double r[20][14])
{
    printf("\nFUNCAO LER_ARQUIVO_GAS.DATA.\n");
    int i, j;

    double id = 0;
    double dia_inicial_de_consumo = 0;
    double mes_inicial_de_consumo = 0;
    double ano_inicial_de_consumo = 0;
    double peso_inicial_total = 0;
    double peso_inicial_do_gas = 0;
    double tara_do_botijao = 0;
    double tara_do_registro = 0;
    double dia_do_termino = 0;
    double mes_do_termino = 0;
    double ano_do_termino = 0;
    double duracao_final_em_dias = 0;
    double zero1 = 0;
    double zero2 = 0;


    //zerando todos os elementos da matriz_do_gas
    for(i = 0; i < 19; i++)
    {
        for(j = 0; j < 14; j++)
        {
            r[i][j] = 0;
        }
    }

    /*criando a variavel ponteiro para o arquivo.*/
    FILE *file;

    //abrindo arquivo
    file = fopen("gas.data","a+");

    /*Preenchendo a matriz com os valores do arquivo.*/
    for(i = 0; i < 20; i++)
    {
        fscanf(file, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\n", &id, &dia_inicial_de_consumo, &mes_inicial_de_consumo, &ano_inicial_de_consumo, &peso_inicial_total, &peso_inicial_do_gas, &tara_do_botijao, &tara_do_registro, &dia_do_termino, &mes_do_termino, &ano_do_termino, &duracao_final_em_dias, &zero1, &zero2);

        r[i][0] = id;
        r[i][1] = dia_inicial_de_consumo;
        r[i][2] = mes_inicial_de_consumo;
        r[i][3] = ano_inicial_de_consumo;
        r[i][4] = peso_inicial_total;
        r[i][5] = peso_inicial_do_gas;
        r[i][6] = tara_do_botijao;
        r[i][7] = tara_do_registro;
        r[i][8] = dia_do_termino;
        r[i][9] = mes_do_termino;
        r[i][10] = ano_do_termino;
        r[i][11] = duracao_final_em_dias;
        r[i][12] = zero1;
        r[i][13] = zero2;
/*
        //Se o primeiro elemento correspondente ao id for zero, entrao o arquivo deve estar vazio.
        if(id == 0){
            printf("\nIniciando captura de dados para o gas 1.\n");
        }
        else{
            printf("\nid = %.0f\n", id);
            printf("\ndia_inicial_de_consumo = %.0f\n", dia_inicial_de_consumo);
            printf("\nmes_inicial_de_consumo = %.0f\n", mes_inicial_de_consumo);
            printf("\nano_inicial_de_consumo = %.0f\n", ano_inicial_de_consumo);
            printf("\npeso_inicial_total = %.1f\n", peso_inicial_total);
            printf("\npeso_inicial_do_gas = %.1f\n", peso_inicial_do_gas);
            printf("\ntara_do_botijao = %.1f\n", tara_do_botijao);
            printf("\ntara_do_registro = %.1f\n", tara_do_registro);
            printf("\ndia_do_termino = %.0f\n", dia_do_termino);
            printf("\nmes_do_termino = %.0f\n", mes_do_termino);
            printf("\nano_do_termino = %.0f\n", ano_do_termino);
            printf("\nduracao_final_em_dias = %.0f\n", duracao_final_em_dias);
        }
*/
    }



    /*fechando o arquivo*/
    fclose(file);

}
void gravar_dados_gas_data(double w[20][14])
{
    printf("\nFUNCAO LER_ARQUIVO_GAS.DATA.\n");
    int i, j;

    double id = 0;
    double dia_inicial_de_consumo = 0;
    double mes_inicial_de_consumo = 0;
    double ano_inicial_de_consumo = 0;
    double peso_inicial_total = 0;
    double peso_inicial_do_gas = 0;
    double tara_do_botijao = 0;
    double tara_do_registro = 0;
    double dia_do_termino = 0;
    double mes_do_termino = 0;
    double ano_do_termino = 0;
    double duracao_final_em_dias = 0;
    double zero1 = 0;
    double zero2 = 0;


    //zerando todos os elementos da matriz_do_gas
    for(i = 0; i < 19; i++)
    {
        for(j = 0; j < 14; j++)
        {
            w[i][j] = 0;
        }
    }

    /*criando a variavel ponteiro para o arquivo.*/
    FILE *file;

    //abrindo arquivo
    file = fopen("gas.data","a+");

    /*Preenchendo a matriz com os valores do arquivo.*/
    for(i = 0; i < 20; i++)
    {
        fscanf(file, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\n", &id, &dia_inicial_de_consumo, &mes_inicial_de_consumo, &ano_inicial_de_consumo, &peso_inicial_total, &peso_inicial_do_gas, &tara_do_botijao, &tara_do_registro, &dia_do_termino, &mes_do_termino, &ano_do_termino, &duracao_final_em_dias, &zero1, &zero2);
        //fprintf(arquivo, "formatos", var1, var2 ...);
        w[i][0] = id;
        w[i][1] = dia_inicial_de_consumo;
        w[i][2] = mes_inicial_de_consumo;
        w[i][3] = ano_inicial_de_consumo;
        w[i][4] = peso_inicial_total;
        w[i][5] = peso_inicial_do_gas;
        w[i][6] = tara_do_botijao;
        w[i][7] = tara_do_registro;
        w[i][8] = dia_do_termino;
        w[i][9] = mes_do_termino;
        w[i][10] = ano_do_termino;
        w[i][11] = duracao_final_em_dias;
        w[i][12] = zero1;
        w[i][13] = zero2;
/*
        //Se o primeiro elemento correspondente ao id for zero, entrao o arquivo deve estar vazio.
        if(id == 0){
            printf("\nIniciando captura de dados para o gas 1.\n");
        }
        else{
            printf("\nid = %.0f\n", id);
            printf("\ndia_inicial_de_consumo = %.0f\n", dia_inicial_de_consumo);
            printf("\nmes_inicial_de_consumo = %.0f\n", mes_inicial_de_consumo);
            printf("\nano_inicial_de_consumo = %.0f\n", ano_inicial_de_consumo);
            printf("\npeso_inicial_total = %.1f\n", peso_inicial_total);
            printf("\npeso_inicial_do_gas = %.1f\n", peso_inicial_do_gas);
            printf("\ntara_do_botijao = %.1f\n", tara_do_botijao);
            printf("\ntara_do_registro = %.1f\n", tara_do_registro);
            printf("\ndia_do_termino = %.0f\n", dia_do_termino);
            printf("\nmes_do_termino = %.0f\n", mes_do_termino);
            printf("\nano_do_termino = %.0f\n", ano_do_termino);
            printf("\nduracao_final_em_dias = %.0f\n", duracao_final_em_dias);
        }
*/
    }



    /*fechando o arquivo*/
    fclose(file);

}
