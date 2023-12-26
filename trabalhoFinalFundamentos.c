#include <stdio.h>
//variaveis globais
char tabuleiro[8][8];            // tabuleiro
int  jogada[48][2];              // jogadas 

// Função que mosta o tabuleiro
void exibe_tabuleiro(){
    
    int linha,coluna;                                   // Declaração das variáveis linha e coluna
    
    printf("\n  1 2 3 4 5 6 7 8");                      // Apresenta a numeração das colunas
    
    for (linha = 0; linha < 8; linha++){
        
        printf("\n%d ", linha+1);                       // Apresenta a numeração das linhas
        
       for (coluna = 0; coluna < 8; coluna++){
           
            printf("%c ",tabuleiro[linha][coluna]);     // Apresenta o que está na linha e coluna indicada
            
        } 
    }
}

//verifica as jogadas
int exibe_jogada(int linha, int coluna){
    
    int i,
        j = 0;     //Declaração i e j
    
    j = 0;
    i = 1;
    
    while(tabuleiro[linha+i][coluna+i] == '*' && (linha + i) <= 7 && (coluna + i) <= 7  ){              // Conta quantas peças tem em uma diagonal até um espaço vazio ou chegar no final
        i++;
    }
    
    if (tabuleiro[linha+1][coluna+1] == '*' && tabuleiro[linha+i][coluna+i] == '-'&& (linha + i) <= 7 && (coluna + i) <= 7 ){ // Verifica se tem peça na diagonal e se há um espaço vazio no final
        
        jogada[j][0] = linha+i; // Atribui a linha destino da peça que foi indicada 
        jogada[j][1] = coluna+i; // Atribui a coluna destino da peça que foi indicada 
        j++;
    }
    
    // Os loops e condicionais seguintes seguem a mesma lógica para as outras diagonais
    i = 1;
    while(tabuleiro[linha+i][coluna-i] == '*'&& (linha + i) <= 7 && (coluna - i) >= 0 ){
        i++;
    }
    if (tabuleiro[linha+1][coluna-1] == '*' && tabuleiro[linha+i][coluna-i] == '-'&& (linha + i) <= 7 && (coluna - i) >= 0 ){
        jogada[j][0] = linha+i;
        jogada[j][1] = coluna-i;
        j++;
    }
    i = 1;
    while(tabuleiro[linha-i][coluna+i] == '*'&& (linha - i) >= 0 && (coluna + i) <= 7  ){
        i++;
    }
    if (tabuleiro[linha-1][coluna+1] == '*' && tabuleiro[linha-i][coluna+i] == '-'&& (linha - i) >= 0 && (coluna + i) <= 7){
        jogada[j][0] = linha-i;
        jogada[j][1] = coluna+i;
        j++;
    }
    i = 1;
    while(tabuleiro[linha-i][coluna-i] == '*'&& (linha - i) >= 0 && (coluna - i) >= 0 ){
        i++;
    }
    if (tabuleiro[linha-1][coluna-1] == '*' && tabuleiro[linha-i][coluna-i] == '-'&& (linha - i) >= 0 && (coluna - i) >= 0){
        jogada[j][0] = linha-i;
        jogada[j][1] = coluna-i;
        j++;
    }
    
    return j;                           // Retorna as jogadas disponíveis
}

//verificar se ainda existe peças moveis
int verificando_derrota(){
    
    int verifica = 0,
         i=0,  
         j=0;                                   // Declaração das variáveis de verificação e indices i e j 
    
    do{
        j=0;
        do{
            if (tabuleiro[i][j] == '*')          // Verifica se existe peça na posição 
                
                verifica =  exibe_jogada(i,j);  // Recebe a quantidade de jogadas na posição
            
            j++;
            
        }while(j <= 7 && verifica == 0 );       // Laço para verificar toda a coluna ou alguma jogada 
        
        i++;
        
    }while(i <= 7 && verifica == 0 );        // Laço para verificar toda a linha ou alguma jogada
    
    return verifica;                         // Retorno
}

// Função que restaura todas as peças
void tabuleiro_n(){
    
    int linha,coluna;                                   // Declaração de linha e coluna
    
    for (linha = 0; linha < 8; linha++){                // Loop passa por todas as linhas
    
        if(linha<=1){                                   // Verifiacação se está na primeira ou segunda linha
        
            for (coluna = 0; coluna< 8; coluna++){      // Loop passa por todas as colunas
            
                tabuleiro[linha][coluna] = '*';         // complemento no novo tabuleiro
                
            }
        
        // Condicionais com logicas semelhantes
        }else{
            if(linha<=5){ 
                for (coluna = 0; coluna< 8; coluna++){
                    if (coluna==0||coluna==1||coluna==6||coluna==7)
                        tabuleiro[linha][coluna] = '*';
                    else
                        tabuleiro[linha][coluna] = '-';
                } 
            }else{
                for (coluna = 0; coluna< 8; coluna++){
                   tabuleiro[linha][coluna] = '*';
                }
            }
        } 
    }


}

// manutenção do jogo
void funcao_jogo(){
    int linha,              //linha
         coluna,            //coluna
         opt,               //opção
         end_gm = 1,        //fim do jogo
         cont,              //contador
         eliminadas = 0,    //eliminada
         saltos = 0;        //saltos 
    
    do{                                             // Laço para continuar as jogadas até o fim 
    
        exibe_tabuleiro();
        
        do{                                         // Laço para verificação se há jogadas no local informada
        
            do{                                     // Laço para verificar se tem uma peça na linha e coluna 
            
                do{                                 // Laço para verificar se a linha e coluna estão dentro do tabuleiro
                    
                    //Entrada linha e coluna
                    printf("\n--> Digite a [linha] da peça que irá jogar, ou [0] para desistir do jogo: ");
                    scanf("%d", &linha);
                    printf("\n--> Digite a [coluna] da peça que irá jogar,ou [0] para desistir do jogo: ");
                    scanf("%d",&coluna );
                    
                    if (linha < 0 || linha > 8 || coluna < 0 || coluna > 8)         // Verifica se é invalido
                        printf("\nCoordenada fora  do tabuleiro! :( Digite novamente!");
                        
                }while(linha < 0 || linha > 8 || coluna < 0 || coluna > 8);
                
                if (tabuleiro[linha-1][coluna-1] != '*' && linha != 0)              // Verifica se é invalido
                    printf("\nNão há jogada na coordenada informada!:( Digite novamente!");
                    
            }while(tabuleiro[linha-1][coluna-1] != '*' && linha != 0);
            
            if (exibe_jogada(linha-1,coluna-1) == 0 && linha != 0)                  // Verifica se é invalido
                printf("\nEssa peça não pode se mover!:( Digite novamente!");
                
        }while(exibe_jogada(linha-1,coluna-1) == 0 && linha != 0);
        
        if (linha == 0){                                                            // Verifica se o jogador quer sair
            end_gm = 0;    
            
        }else{
            
             // Reajuste das variáveis 
            linha = linha - 1;
            coluna = coluna - 1; 
            
            do{                                                                     // Laço de verificação da opção 
            
                //Apresentação das opções
                printf("Escolha uma das opções: [0 --> escolher outra peça]");
                
                printf(" Digite [1 --> para confirmar sua escolha] ");
                
                // Entrada da opção 
                scanf(" %d", &opt);
                
            }while (opt < 0 || opt > exibe_jogada(linha,coluna));
            
            cont = 0;
            
            if (opt != 0){                                              // Verifica se a opção escolhida não foi escolher outra peça para jogar
            
                if (linha > jogada[opt-1][0]){                          // Verifica se a peça de origem está após seu destino
                
                    if (coluna > jogada[opt-1][1]){                     // Verifica se a peça de origem está a direita do seu destino
                        
                        while (linha - (jogada[opt-1][0]+cont) != 1){   // Laço para contar as peças eliminadas para retira-las do tabuleiro
                            cont++;
                            tabuleiro[linha-cont][coluna-cont] = '-';
                            eliminadas++;
                        }
                    
                    // Os laços a seguir repetem a lógica
                    }else{
                        while (linha - (jogada[opt-1][0]+cont) != 1){
                            cont++;
                            tabuleiro[linha-cont][coluna+cont] = '-';
                            eliminadas++;
                        }
                    }    
                }else{
                    if (coluna > jogada[opt-1][1]){
                        while (jogada[opt-1][0] - (linha+cont) != 1){
                            cont++;
                            tabuleiro[linha+cont][coluna-cont] = '-';
                            eliminadas++;
                        }
                    }else{
                        while (jogada[opt-1][0] - (linha+cont) != 1){
                            cont++;
                            tabuleiro[linha+cont][coluna+cont] = '-';
                            eliminadas++;
                        }
                    }    
                }
                saltos++; // conta saltos
                
                // move a peça de origem para o seu destino
                tabuleiro[linha][coluna] = '-';
                tabuleiro[jogada[opt-1][0]][jogada[opt-1][1]] = '*'; 
                
                // Apresentação dos dados do salto
                printf("\n**Salto de -> [%d %d] para -> [%d %d] com %d pedra(s) eliminada(s) neste salto.**",linha+1, coluna+1, jogada[opt-1][0]+1,jogada[opt-1][1]+1, cont);
                printf("\n%d **pedras eliminadas; restam %d pedras no tabuleiro.**\n\n",eliminadas, 48 - eliminadas);
                
            }
            
            if (verificando_derrota() == 0) // Verifica se houve derrota 
                end_gm = 0;  //retorna 0 
        }   
        
    }while(end_gm == 1); //não houve derrota
    
    // resultado do jogo
    printf("\n\n");
    exibe_tabuleiro();
    
    // nivel alcançado 
    if(eliminadas <= 29){ 
        printf("\n\n**Parabéns você conseguiu atingir o nível extremamente fácil :) , com %d saltos e %d peças eliminadas**",saltos, eliminadas);
    
    }else{
        if(eliminadas <= 39){
            printf("\n\n **Parabéns você conseguiu atingir o nível fácil :), com %d saltos e %d peças eliminadas**",saltos, eliminadas);
    
        }else{
            if(eliminadas <= 49){
                printf("\n\n **Parabéns você conseguiu atingir o nível difícil :), com %d saltos e %d peças eliminadas**",saltos, eliminadas);
    
            }else{
                printf("\n\n **Parabéns você conseguiu atingir o nível extremamente difícil :), com %d saltos e %d peças eliminadas**",saltos, eliminadas);
            }
        }
    }
}

int main(){
    
    int escolha;                                                                        // Declaração da variável opção
    
    printf("\n**** Bem vindo ao game seu lindo! ****\n");
    
    do{                                                                             // Laço para continuar até que o jogador queira sair
        printf("\n -----------------======================---------------------------------");
        printf("\n<");
        printf("** Escolha entre opções vossa majestade: [0 -> Sair] [1 -> Novo Jogo] ** ");
        printf(">");
        printf("\n -----------------======================---------------------------------\n");
        do{                                                                         // Verifica se a opção escolhia esta dentro dos limites
            
            // Entrada da escolha do jogador
            scanf("%d", &escolha);
            
            if(escolha < 0 || escolha > 1)                                                  // Verificação para mensagem de invalidade
                printf("** Opção inválida, burrão!!!Digite novamente **\n");
                
        }while(escolha < 0 || escolha > 1);
        
        // Verifica se escolheu um novo jogo
        if(escolha == 1){
            tabuleiro_n();
            funcao_jogo();
        }
        
    }while(escolha != 0);
    //fim do programa
    return 0;
}


