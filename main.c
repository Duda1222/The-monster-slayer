#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <hora.h>
#include<locale.h>




#define MAP_SIZE 5
#define MAX_MONSTROS 3
#define MAX_HEALTH 100
#define MAX_ATTACK 20
#define MAX_EXP 100
#define MAX_LEVEL 10
#define MAX_WATER_STEPS 3
#define MAX_SAME_DIRECTION_STEPS 4
#define INVENTORY_SIZE 5








// Estrutura para representar um item do inventário
estrutura typedef {
   nome do caracter[20];
   quantidade interna;
} ItemInventário;


//Estrutura para representar o inventário do jogador
estrutura typedef {
   Itens de item de inventário[INVENTORY_SIZE];
   int contagem de itens;
} Inventário;


// Estrutura para representar um monstruoso
estrutura typedef {
   nome do caracter[20];
   saúde interna;
   ataque interno;
   int exp;
} Monstro;
estrutura typedef {
   Monstro monstro;
   int playerSaúde;
   int playerExp;
   int jogadorX;
   int jogadorY;
} Estado de Batalha;


// Variável global para armazenar o estado da última batalha
BattleState últimaBatalha;


// Protótipos das funções
int randomInt(int min, int max);
void printMap(mapa de caracteres[MAP_SIZE][MAP_SIZE], int playerX, int playerY);
batalha bool(Monstro *monstro, int *playerHealth, int *playerExp, Inventário *inventário, int
*playerX, int *playerY, int *playerLevel);
void addItemToInventory(Inventário *inventário, const char *itemName, int quantidade);
void saveGame(const char *fileName, int playerX, int playerY, int playerHealth, int
playerExp, int playerLevel, const Inventário *inventário);
bool loadGame(const char *nomedoarquivo, int *playerX, int *playerY, int *playerHealth, int
*playerExp, int *playerLevel, Inventário *inventário);
void generateMap(mapa de char[MAP_SIZE][MAP_SIZE], int x, int y);


// Função para gerar um número aleatório entre min e max
int randomInt(int mínimo, int máximo) {
   retornar min + rand()% (máx - min + 1);
}


// Função para imprimir o mapa
void printMap(mapa de caracteres[MAP_SIZE][MAP_SIZE], int playerX, int playerY) {
   for (int i = 0; i < MAP_SIZE; i++) {
       for (int j = 0; j < MAP_SIZE; j++) {
           if (i == jogadorY && j == jogadorX) {
               printf("P ");
           } outro {
               printf("%c ", mapa[i][j]);
           }
       }
       printf("\n");
   }
}
 bool loadGame(const char *fileName, int *playerX, int *playerY, int *playerHealth, int *playerExp, int *playerLevel, Inventário *inventário) {
    ARQUIVO *arquivo = fopen(nomeArquivo, "r");
    if (arquivo! = NULO) {


       fread(playerX, sizeof(int), 1, arquivo);
       fread(playerY, sizeof(int), 1, arquivo);
       fread(playerHealth, sizeof(int), 1, arquivo);
       fread(playerExp, sizeof(int), 1, arquivo);
       fread(playerLevel, sizeof(int), 1, arquivo);
       fread(inventário, sizeof(Inventário), 1, arquivo);
       fclose(arquivo);
       printf("Jogo carregado com sucesso!\n");
       retornar verdadeiro;
   } outro {
       printf("Erro ao carregar o jogo! Iniciando um novo jogo...\n");
       *jogadorX = 1;
      *jogadorY = 1;
      *playerHealth = MAX_HEALTH;
      *playerExp = 0;
      *playerLevel = 1;
      inventário->itemCount = 0;
      retorna falso;
  }
}
// Função para realizar uma batalha entre o jogador e um monstro
batalha bool(Monstro *monstro, int *playerHealth, int *playerExp, Inventário *inventário, int
*playerX, int *playerY, int *playerLevel) {
   printf("Você encontrou um %s!\n", monstro->nome);
   printf(" .' . . . . .''.\n");
printf(" .' . . . . . . ..:.\n");
printf(" .' . . . . . . .. . . ....::.\n");
printf(" .. . . . . . . .. . ....:IA.\n");
printf(" .: . . . . . . .. . .. .. ....:IA.\n");
printf(" .: . . .. . . . . .. . ... ....:.:VHA.\n");
printf(" '.. . .. . . . . .. . .. . .....:.::IHHB.\n");
printf(" .:. . . . . . . . . . . ...:.:... .......:HIHMM.\n");
printf(" .:.... . . .::.. . . . .:.:.:II;,. .. ..:IHIMMA\n");
printf(" ':.:.. ..::IHHHHHI::. . . ...:.::::.,,,. . ....VIMMHM\n");
printf(" .:::I. .AHHHHHHHHHHAI::. .:...,:IIHHHHHHMMMHHL:. . VMMMM\n");
printf(" .:.:V.:IVHHHHHHHMHMHHH::..: .:HIHHHHHHHHHHHHMHHA. .VMMM.\n");
printf(" :..V.:IVHHHHHMMHHHHHHHB... . .:VPHHMHHHMMHHHHHHHHHAI.:WMM\n");
printf(" ::V..:VIHHHHHHMMMHHHHHH. . .I:IIMHHMMHHHHHHHHHHAPI:WMM\n");
printf(" ::. .:.HHHHHHHHMMHHHHHI. .:..I:MHMMHHHHHHHHHMHV:' .IHWW\n");
printf(" :: . :.::IIHHHHHHMMHHHHV .ABA.:.:IMHMHMMMHMHHHHV:' . :IHWV\n");
printf(" :. ..:..:.:IHHHHHMMHV .AVMHMA.:.'VHMMMMHHHHHV:' . :IVAI\n");
printf(" :. .:...::.:.:TPP .AVMMHMMA.:. VMMHHHP.:... .. :IVAI\n");
printf(" .:. '... .: . ..HMMMHMMMA::. . VHHI:::.... .:IHW'\n");
printf(" ... . . .. ..:IIPPIH: ..HMMMI.MMMV:I:. .:ILLH:.. ...:I:IM\n");
printf(": . .' ... .. . .\n");
printf(":. . . .. ..:.. . :AMMM IMMMM..:...:IV:T::I::.\n");
printf("'V:.. .. . .. . . . 'VMMV..VMMV :....:V:.:..:....::IHHHMH\n");
printf("IHH:.II:.. .:. . . . . :HB . . ..PI:.::.:::..:IHHMMV\n");
printf(" :IPHHII:. . . . . .'V:. . . ..:IH:.:.::IHIHHMMMMM\n");
printf(" :V:. VIMA:I.. . . . .. . . .:.I:I:..:IHHHHMMHHMMM\n");
printf(" :.VIIHHMMA:. .: . .. .:. ..:.I::.:IVHHHMMMHMMMMI\n");
printf(" :..VIHIHMMMI...::.,:.,:!I:!!V:AI:VAMMMMMMHMMMMMM'\n");
printf(" ':.:HIHIMHHA:!!I.:AXXXVVXXXXXXXA:.HPHIMMMMHHMHMMMMMV\n");
printf(" V:H:I:MA:W'I :AXXXIXII:IIIISSSSSSXXA.I.VMMMHMHMMMMMM\n");
printf("'I::IVA ASSSSXSSSSBSBMBSSSSSSBBMMMBS.VVMMHIMM'\n");
printf("I::VPAIMSSSSSSSSBSSSMMBSSSBBMMMMXXI:MMHIMMI\n");
printf(" .I::. H:XIIXBBMMMMMMMMMMMMMMMBXIXXMMPHIIMM'\n");
printf(" :::I. ':XSSXXIIIIXSSBMBSSXXXIIIXXSMMAMI:.IMM\n");
printf(" :::I:. .VSSSSSISISSSBII:ISSSSBMMB:MI:..:MM\n");
printf(" ::.I:. ':SSSSSSSISISSXIIXSSSSBMMB:AHI:..MMM.\n");
printf(" ::.I:. . ..:::BBBBBSSBBBMMMB:MMMMHHII::IHHMI\n");
printf(" :..::. . .. . ...:::IIHHMMMMHMV\n");
printf(" V:. ..:...:.IHHMMV\n");


   while (*playerHealth > 0 && monstro->saúde > 0) {
     printf("Sua saúde: %d\n", *playerHealth);
     printf("Saúde do monstro: %d\n", monstro->saúde);
     printf("1. Atacar\n2. Fugir\np. Salvar jogo\nl. Carregar jogo\nq. Sair do jogo\n");
     escolha de caractere[20];
     scanf("%s", escolha);
     if (strcmp(escolha, "1") == 0) {
         dano interno = randomInt(1, MAX_ATTACK);
         monstro->saúde -=dano;
         printf("Você sofreu %d de dano!\n", dano);
         if (monstro->saúde > 0) {
             dano = randomInt(1, monstro->ataque);
             *playerHealth -= dano;
             printf("O monstro apaixonado %d de dano!\n", dano);
         }
     } else if (strcmp(escolha, "2") == 0) {
         printf("Covarde! Você fugiu da batalha!\n");
         retorna falso;
     } else if (strcmp(escolha, "p") == 0) {
         saveGame("savegame.bin", playerX, playerY, *playerHealth, *playerExp,
nível do jogador, inventário);
         printf("Salvo com sucesso\n");
      } else if (strcmp(choice, "l") == 0) {


       printf("\n Último estado do jogador:\n");
       printf("\n Posição: (%d, %d)\n", lastBattle.playerX, lastBattle.playerY);
       printf("\n Saúde: %d\n", lastBattle.playerHealth);
       printf(" \n Experiência: %d\n", lastBattle.playerExp);
       printf("\n Monstro: %s\n", lastBattle.monster.name);


       } else if (strcmp(escolha, "q") == 0) {
          saveGame("savegame.bin", playerX, playerY, *playerHealth, *playerExp,
nível do jogador, inventário);
          printf("Saindo do jogo...\n");
          saída(0);
       } outro {
          printf("Opção invalida!\n");
       }
   }
   if (*Saúde do jogador > 0) {
       printf("Você derrotou o %se ganhou %d de experiência!\n", monstro->nome,
monstro->exp);
       *playerExp += monstro->exp;
      // Adiciona um item aleatório ao inventário quando o jogador vence a batalha
      int randRecompensa = rand() % 3;
      switch(randRecompensa) {
         caso 0:
            addItemToInventory(inventário, "Pocão Mágico", 1);
            printf("Você ganhou um Pocão Mágico!\n");
            quebrar;
         caso 1:
            addItemToInventory(inventário, "Pedra Preciosa", 1);
            printf("Você encontrou uma Pedra Preciosa!\n");
            quebrar;
         padrão:
            addItemToInventory(inventário, "Arco e flecha", 1);
            printf("Você ganhou um arco e flecha!\n");
            quebrar;
      }


       retornar verdadeiro;
    } outro {
       printf("Você foi derrotado pelo %s!\n", monstro->nome);
       retorna falso;
    }
}


// Função para adicionar um item ao inventário
void addItemToInventory(Inventário *inventário, const char *itemName, int quantidade) {
   if (inventário->itemCount <INVENTORY_SIZE) {
       for (int i = 0; i < inventário->itemCount; i++) {
           if (strcmp(inventário->items[i].nome, itemName) == 0) {
               inventário->itens[i].quantidade += quantidade;
               retornar;
           }
       }
       strcpy(inventário->itens[inventário->itemCount].nome, itemName);
       inventário->itens[inventário->itemCount].quantidade = quantidade;
       inventário->itemCount++;
   } outro {
       printf("Inventário cheio! Não foi possível adicionar o item.\n");
   }
}
// Função para salvar o estado do jogador em um arquivo binário
void saveGame(const char *fileName, int playerX, int playerY, int playerHealth, int playerExp, int playerLevel, const Inventário *inventário) {
    ARQUIVO *arquivo = fopen(nomeArquivo, "w");
    if (arquivo! = NULO) {
        fprintf(arquivo, "{\n");
        fprintf(arquivo, " \"playerX\": %d,\n", playerX);
        fprintf(arquivo, " \"playerY\": %d,\n", playerY);
        fprintf(arquivo, " \"playerHealth\": %d,\n", playerHealth);
        fprintf(arquivo, " \"playerExp\": %d,\n", playerExp);
        fprintf(arquivo, " \"playerLevel\": %d,\n", playerLevel);
        fprintf(arquivo, " \"inventário\": {\n");
        fprintf(arquivo, " \"itens\": [\n");
        for (int i = 0; i < inventário->itemCount; i++) {
            fprintf(arquivo, " {\"nome\": \"%s\", \"quantidade\": %d}", inventário->itens[i].nome, inventário->itens[i].quantidade) ;
            if (i <inventário->itemCount - 1) {
                fprintf(arquivo, ",");
            }
            fprintf(arquivo, "\n");
        }
        fprintf(arquivo, "]\n");
        fprintf(arquivo, " }\n");
        fprintf(arquivo, "}\n");
        fclose(arquivo);
        printf("Jogo salvo com sucesso!\n");
    } outro {
        printf("Erro ao salvar o jogo!\n");
    }
}
// Função recursiva para gerar o mapa
void generateMap(mapa de char[MAP_SIZE][MAP_SIZE], int x, int y) {
   // Condição de parada da recursão
   if (x < 0 || x >= MAP_SIZE || y < 0 || y >= MAP_SIZE || mapa[y][x] != ' ') {
       retornar;
   }


    // Preencher a posição atual com algum tipo de terreno
    mapa[y][x] = '.';


    // Chamadas recursivas para as quatro possibilidades possíveis
    gerarMap(mapa, x + 1, y);
    generateMap(mapa, x - 1, y);
    gerarMapa(mapa, x, y + 1);
    generateMap(mapa, x, y - 1);
}


int principal() {
    setlocale(LC_ALL, "Português");


    srand(tempo(NULO));
     int playerX, playerY, playerHealth, playerExp, playerLevel;
    Jogador de inventárioInventário;




   menu charChoice;
   fazer {
      printf(" \n Bem Vindo(a) ao The Monster Slayer 2 \n");
   printf("\nMenu: \n");
         printf("(n)Novo Jogo\n");
printf(" (h) Como Jogar\n");
printf("(c) Créditos\n");
printf(" (p) Salvar Jogo\n"); // Alterado para 'p' para salvar o jogo
printf(" (l) Carregar Jogo\n");
printf(" (L) Mostrar último estado do jogador\n"); // Adicionado para mostrar o último estado do jogador
printf("(q)Sair\n");
printf("Escolha uma opção: ");
scanf("%c", &menuChoice);




     switch (menuEscolha) {
       caso 'n': {
          //Posição inicial do jogador
           jogadorX = 1;
            jogadorY = 1;


          // Atributos do jogador
          int saúde do jogador = MAX_HEALTH;
          int playerExp = 0;
          int nível do jogador = 1;
          int waterSteps = 0;
          int SameDirectionSteps = 0;
          char últimaDireção = '\0';


          // Inventário do jogador
          Jogador de inventárioInventário;
          playerInventory.itemCount = 0;


          //Array de monstros
          Monstros monstros[MAX_MONSTERS] = {
             {"Goblin", 30, 10, 20},
             {"Esqueleto", 40, 15, 30},
             {"Dragão", 50, 20, 50}
          };
          printf("Boa sorte! \n");


         while (playerHealth > 0 && playerLevel < MAX_LEVEL) {
           //Mapa do jogo
           mapa de caracteres[MAP_SIZE][MAP_SIZE] = {
              {'#', '#', '#', '#', '#'},
              {'#', '.', '.', '.', '#'},
              {'#', '.', '#', '.', '#'},
              {'#', '.', '.', '.', '#'},
              {'#', '#', '#', '#', '#'}
           };
           printf("Nível: %d | Experiência: %d/%d | Saúde: %d/%d\n", playerLevel,
playerExp,
                 MAX_EXP, saúde do jogador, MAX_HEALTH);
           printMap(mapa, playerX, playerY);
           printf("Escolha a direção (w/a/s/d): ");
           direção do caractere;
           scanf("%c", &direção);
           int novoX = jogadorX, novoY = jogadorY;
             // Verifica se a direção mudou
             if (direção! = últimaDireção) {
                 sameDirectionSteps = 0;
                 últimaDireção = direção;
             }
             mudar (direção) {
                 caso 'w': novoY--; quebrar;
                 caso 'a': novoX--; quebrar;
                 case 's': novoY++; quebrar;
                 caso 'd': novoX++; quebrar;
                 case 'i': // Opção para abrir o inventário
                     printf("Inventário:\n");
                     for (int i = 0; i < playerInventory.itemCount; i++) {
                        printf("%s: %d\n", playerInventory.items[i].nome,
                              playerInventory.items[i].quantidade);
                     }
                     continuar;
                 padrão: printf("Direção invalida!\n"); continuar;
             }
             // Verifique se o jogador está andando muito na mesma direção
             if (direção == lastDirection && ++sameDirectionSteps >
MAX_SAME_DIRECTION_STEPS) {
                 printf("Apenas água nessa direção!\n");
                 continuar;
             }
             // Verifica se o jogador está andando na água por muito tempo
             if (mapa[newY][newX] == '~' && ++waterSteps > MAX_WATER_STEPS) {
                 printf("Apenas água nessa direção!\n");
                 continuar;
             }
             // Reinicia o contador de passos na água quando o jogador muda de direção
             if (direção! = últimaDireção) {
                 passos de água = 0;
             }
             if (novoX >= 0 && novoX < MAP_SIZE && novoY >= 0 && novoY < MAP_SIZE &&
                 mapa[novoY][novoX] != '#') {
                 jogadorX = novoX;
                 jogadorY = novoY;
                 if (mapa[newY][newX] == '.') {
                     int monsterIndex = randomInt(0, MAX_MONSTERS - 1);
                   if (battle(&monstros[monsterIndex], &playerHealth, &playerExp,
&playerInventory, &playerX, &playerY, &playerLevel)) {
  mapa[novoY][novoX] = 'M'; // M representa um monstro no mapa
  lastBattle.monster = monstros[monsterIndex];
  lastBattle.playerHealth = playerHealth;
  lastBattle.playerExp = playerExp;
  últimaBatalha.jogadorX = jogadorX;
  últimaBatalha.playerY = jogadorY;
}




               }
            } outro {
               printf("Movimento inválido!\n");
            }
          }
          if (Saúde do jogador <= 0) {
              printf("Você morreu!\n");
          } else if (playerLevel >= MAX_LEVEL) {
              printf("Parabenos, você alcançou o nível máximo!\n");
          }


          quebrar;
}
caso 'p': {
  // Salvar o jogo
  saveGame("savegame.bin", playerX, playerY, playerHealth, playerExp, playerLevel,
&playerInventário);
  quebrar;
}


case 'L': { // Adicione este bloco
  printf("Último estado do jogador:\n");
  printf("Posição: (%d, %d)\n", lastBattle.playerX, lastBattle.playerY);
  printf("Saúde: %d\n", lastBattle.playerHealth);
  printf("Experiência: %d\n", lastBattle.playerExp);
  printf("Monstro: %s\n", lastBattle.monster.name);
  quebrar;
}
        caso 'h':
            // Opção para explicar como jogar
            printf("\nComo Jogar:\n");
            printf("1. Use as teclas 'w', 'a', 's' e 'd' para se mover pelo mapa.\n");
            printf("2. Encontre monstros no mapa e entre na batalha com eles.\n");
            printf("3. Durante a batalha, escolha entre atacar ou fugir 1 ou 2, respectivamente.\n");
            printf("4. Ao derrotar um monstro, você ganha experiência e pode obter recompensas.\n");
            printf("5. O jogo continua até você atingir o nível máximo ou perder toda a sua saúde.\n");
            quebrar;
        caso 'c':


         printf("Créditos: Maria Eduarda A. Lopes, Antonio V., João Pedro \n");
         quebrar;
       caso 'd':
                //


          quebrar;


          caso 'q':
            printf("Saindo do jogo...\n");
            quebrar;
          padrão:
            printf("Opção invalida! Tente novamente.\n");
      }


    } while (menuChoice! = 'q');


    retornar 0;
}
