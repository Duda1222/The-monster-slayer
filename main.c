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








// Estrutura para representar um item do invent�rio
estrutura typedef {
   nome do caracter[20];
   quantidade interna;
} ItemInvent�rio;


//Estrutura para representar o invent�rio do jogador
estrutura typedef {
   Itens de item de invent�rio[INVENTORY_SIZE];
   int contagem de itens;
} Invent�rio;


// Estrutura para representar um monstruoso
estrutura typedef {
   nome do caracter[20];
   sa�de interna;
   ataque interno;
   int exp;
} Monstro;
estrutura typedef {
   Monstro monstro;
   int playerSa�de;
   int playerExp;
   int jogadorX;
   int jogadorY;
} Estado de Batalha;


// Vari�vel global para armazenar o estado da �ltima batalha
BattleState �ltimaBatalha;


// Prot�tipos das fun��es
int randomInt(int min, int max);
void printMap(mapa de caracteres[MAP_SIZE][MAP_SIZE], int playerX, int playerY);
batalha bool(Monstro *monstro, int *playerHealth, int *playerExp, Invent�rio *invent�rio, int
*playerX, int *playerY, int *playerLevel);
void addItemToInventory(Invent�rio *invent�rio, const char *itemName, int quantidade);
void saveGame(const char *fileName, int playerX, int playerY, int playerHealth, int
playerExp, int playerLevel, const Invent�rio *invent�rio);
bool loadGame(const char *nomedoarquivo, int *playerX, int *playerY, int *playerHealth, int
*playerExp, int *playerLevel, Invent�rio *invent�rio);
void generateMap(mapa de char[MAP_SIZE][MAP_SIZE], int x, int y);


// Fun��o para gerar um n�mero aleat�rio entre min e max
int randomInt(int m�nimo, int m�ximo) {
   retornar min + rand()% (m�x - min + 1);
}


// Fun��o para imprimir o mapa
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
 bool loadGame(const char *fileName, int *playerX, int *playerY, int *playerHealth, int *playerExp, int *playerLevel, Invent�rio *invent�rio) {
    ARQUIVO *arquivo = fopen(nomeArquivo, "r");
    if (arquivo! = NULO) {


       fread(playerX, sizeof(int), 1, arquivo);
       fread(playerY, sizeof(int), 1, arquivo);
       fread(playerHealth, sizeof(int), 1, arquivo);
       fread(playerExp, sizeof(int), 1, arquivo);
       fread(playerLevel, sizeof(int), 1, arquivo);
       fread(invent�rio, sizeof(Invent�rio), 1, arquivo);
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
      invent�rio->itemCount = 0;
      retorna falso;
  }
}
// Fun��o para realizar uma batalha entre o jogador e um monstro
batalha bool(Monstro *monstro, int *playerHealth, int *playerExp, Invent�rio *invent�rio, int
*playerX, int *playerY, int *playerLevel) {
   printf("Voc� encontrou um %s!\n", monstro->nome);
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


   while (*playerHealth > 0 && monstro->sa�de > 0) {
     printf("Sua sa�de: %d\n", *playerHealth);
     printf("Sa�de do monstro: %d\n", monstro->sa�de);
     printf("1. Atacar\n2. Fugir\np. Salvar jogo\nl. Carregar jogo\nq. Sair do jogo\n");
     escolha de caractere[20];
     scanf("%s", escolha);
     if (strcmp(escolha, "1") == 0) {
         dano interno = randomInt(1, MAX_ATTACK);
         monstro->sa�de -=dano;
         printf("Voc� sofreu %d de dano!\n", dano);
         if (monstro->sa�de > 0) {
             dano = randomInt(1, monstro->ataque);
             *playerHealth -= dano;
             printf("O monstro apaixonado %d de dano!\n", dano);
         }
     } else if (strcmp(escolha, "2") == 0) {
         printf("Covarde! Voc� fugiu da batalha!\n");
         retorna falso;
     } else if (strcmp(escolha, "p") == 0) {
         saveGame("savegame.bin", playerX, playerY, *playerHealth, *playerExp,
n�vel do jogador, invent�rio);
         printf("Salvo com sucesso\n");
      } else if (strcmp(choice, "l") == 0) {


       printf("\n �ltimo estado do jogador:\n");
       printf("\n Posi��o: (%d, %d)\n", lastBattle.playerX, lastBattle.playerY);
       printf("\n Sa�de: %d\n", lastBattle.playerHealth);
       printf(" \n Experi�ncia: %d\n", lastBattle.playerExp);
       printf("\n Monstro: %s\n", lastBattle.monster.name);


       } else if (strcmp(escolha, "q") == 0) {
          saveGame("savegame.bin", playerX, playerY, *playerHealth, *playerExp,
n�vel do jogador, invent�rio);
          printf("Saindo do jogo...\n");
          sa�da(0);
       } outro {
          printf("Op��o invalida!\n");
       }
   }
   if (*Sa�de do jogador > 0) {
       printf("Voc� derrotou o %se ganhou %d de experi�ncia!\n", monstro->nome,
monstro->exp);
       *playerExp += monstro->exp;
      // Adiciona um item aleat�rio ao invent�rio quando o jogador vence a batalha
      int randRecompensa = rand() % 3;
      switch(randRecompensa) {
         caso 0:
            addItemToInventory(invent�rio, "Poc�o M�gico", 1);
            printf("Voc� ganhou um Poc�o M�gico!\n");
            quebrar;
         caso 1:
            addItemToInventory(invent�rio, "Pedra Preciosa", 1);
            printf("Voc� encontrou uma Pedra Preciosa!\n");
            quebrar;
         padr�o:
            addItemToInventory(invent�rio, "Arco e flecha", 1);
            printf("Voc� ganhou um arco e flecha!\n");
            quebrar;
      }


       retornar verdadeiro;
    } outro {
       printf("Voc� foi derrotado pelo %s!\n", monstro->nome);
       retorna falso;
    }
}


// Fun��o para adicionar um item ao invent�rio
void addItemToInventory(Invent�rio *invent�rio, const char *itemName, int quantidade) {
   if (invent�rio->itemCount <INVENTORY_SIZE) {
       for (int i = 0; i < invent�rio->itemCount; i++) {
           if (strcmp(invent�rio->items[i].nome, itemName) == 0) {
               invent�rio->itens[i].quantidade += quantidade;
               retornar;
           }
       }
       strcpy(invent�rio->itens[invent�rio->itemCount].nome, itemName);
       invent�rio->itens[invent�rio->itemCount].quantidade = quantidade;
       invent�rio->itemCount++;
   } outro {
       printf("Invent�rio cheio! N�o foi poss�vel adicionar o item.\n");
   }
}
// Fun��o para salvar o estado do jogador em um arquivo bin�rio
void saveGame(const char *fileName, int playerX, int playerY, int playerHealth, int playerExp, int playerLevel, const Invent�rio *invent�rio) {
    ARQUIVO *arquivo = fopen(nomeArquivo, "w");
    if (arquivo! = NULO) {
        fprintf(arquivo, "{\n");
        fprintf(arquivo, " \"playerX\": %d,\n", playerX);
        fprintf(arquivo, " \"playerY\": %d,\n", playerY);
        fprintf(arquivo, " \"playerHealth\": %d,\n", playerHealth);
        fprintf(arquivo, " \"playerExp\": %d,\n", playerExp);
        fprintf(arquivo, " \"playerLevel\": %d,\n", playerLevel);
        fprintf(arquivo, " \"invent�rio\": {\n");
        fprintf(arquivo, " \"itens\": [\n");
        for (int i = 0; i < invent�rio->itemCount; i++) {
            fprintf(arquivo, " {\"nome\": \"%s\", \"quantidade\": %d}", invent�rio->itens[i].nome, invent�rio->itens[i].quantidade) ;
            if (i <invent�rio->itemCount - 1) {
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
// Fun��o recursiva para gerar o mapa
void generateMap(mapa de char[MAP_SIZE][MAP_SIZE], int x, int y) {
   // Condi��o de parada da recurs�o
   if (x < 0 || x >= MAP_SIZE || y < 0 || y >= MAP_SIZE || mapa[y][x] != ' ') {
       retornar;
   }


    // Preencher a posi��o atual com algum tipo de terreno
    mapa[y][x] = '.';


    // Chamadas recursivas para as quatro possibilidades poss�veis
    gerarMap(mapa, x + 1, y);
    generateMap(mapa, x - 1, y);
    gerarMapa(mapa, x, y + 1);
    generateMap(mapa, x, y - 1);
}


int principal() {
    setlocale(LC_ALL, "Portugu�s");


    srand(tempo(NULO));
     int playerX, playerY, playerHealth, playerExp, playerLevel;
    Jogador de invent�rioInvent�rio;




   menu charChoice;
   fazer {
      printf(" \n Bem Vindo(a) ao The Monster Slayer 2 \n");
   printf("\nMenu: \n");
         printf("(n)Novo Jogo\n");
printf(" (h) Como Jogar\n");
printf("(c) Cr�ditos\n");
printf(" (p) Salvar Jogo\n"); // Alterado para 'p' para salvar o jogo
printf(" (l) Carregar Jogo\n");
printf(" (L) Mostrar �ltimo estado do jogador\n"); // Adicionado para mostrar o �ltimo estado do jogador
printf("(q)Sair\n");
printf("Escolha uma op��o: ");
scanf("%c", &menuChoice);




     switch (menuEscolha) {
       caso 'n': {
          //Posi��o inicial do jogador
           jogadorX = 1;
            jogadorY = 1;


          // Atributos do jogador
          int sa�de do jogador = MAX_HEALTH;
          int playerExp = 0;
          int n�vel do jogador = 1;
          int waterSteps = 0;
          int SameDirectionSteps = 0;
          char �ltimaDire��o = '\0';


          // Invent�rio do jogador
          Jogador de invent�rioInvent�rio;
          playerInventory.itemCount = 0;


          //Array de monstros
          Monstros monstros[MAX_MONSTERS] = {
             {"Goblin", 30, 10, 20},
             {"Esqueleto", 40, 15, 30},
             {"Drag�o", 50, 20, 50}
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
           printf("N�vel: %d | Experi�ncia: %d/%d | Sa�de: %d/%d\n", playerLevel,
playerExp,
                 MAX_EXP, sa�de do jogador, MAX_HEALTH);
           printMap(mapa, playerX, playerY);
           printf("Escolha a dire��o (w/a/s/d): ");
           dire��o do caractere;
           scanf("%c", &dire��o);
           int novoX = jogadorX, novoY = jogadorY;
             // Verifica se a dire��o mudou
             if (dire��o! = �ltimaDire��o) {
                 sameDirectionSteps = 0;
                 �ltimaDire��o = dire��o;
             }
             mudar (dire��o) {
                 caso 'w': novoY--; quebrar;
                 caso 'a': novoX--; quebrar;
                 case 's': novoY++; quebrar;
                 caso 'd': novoX++; quebrar;
                 case 'i': // Op��o para abrir o invent�rio
                     printf("Invent�rio:\n");
                     for (int i = 0; i < playerInventory.itemCount; i++) {
                        printf("%s: %d\n", playerInventory.items[i].nome,
                              playerInventory.items[i].quantidade);
                     }
                     continuar;
                 padr�o: printf("Dire��o invalida!\n"); continuar;
             }
             // Verifique se o jogador est� andando muito na mesma dire��o
             if (dire��o == lastDirection && ++sameDirectionSteps >
MAX_SAME_DIRECTION_STEPS) {
                 printf("Apenas �gua nessa dire��o!\n");
                 continuar;
             }
             // Verifica se o jogador est� andando na �gua por muito tempo
             if (mapa[newY][newX] == '~' && ++waterSteps > MAX_WATER_STEPS) {
                 printf("Apenas �gua nessa dire��o!\n");
                 continuar;
             }
             // Reinicia o contador de passos na �gua quando o jogador muda de dire��o
             if (dire��o! = �ltimaDire��o) {
                 passos de �gua = 0;
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
  �ltimaBatalha.jogadorX = jogadorX;
  �ltimaBatalha.playerY = jogadorY;
}




               }
            } outro {
               printf("Movimento inv�lido!\n");
            }
          }
          if (Sa�de do jogador <= 0) {
              printf("Voc� morreu!\n");
          } else if (playerLevel >= MAX_LEVEL) {
              printf("Parabenos, voc� alcan�ou o n�vel m�ximo!\n");
          }


          quebrar;
}
caso 'p': {
  // Salvar o jogo
  saveGame("savegame.bin", playerX, playerY, playerHealth, playerExp, playerLevel,
&playerInvent�rio);
  quebrar;
}


case 'L': { // Adicione este bloco
  printf("�ltimo estado do jogador:\n");
  printf("Posi��o: (%d, %d)\n", lastBattle.playerX, lastBattle.playerY);
  printf("Sa�de: %d\n", lastBattle.playerHealth);
  printf("Experi�ncia: %d\n", lastBattle.playerExp);
  printf("Monstro: %s\n", lastBattle.monster.name);
  quebrar;
}
        caso 'h':
            // Op��o para explicar como jogar
            printf("\nComo Jogar:\n");
            printf("1. Use as teclas 'w', 'a', 's' e 'd' para se mover pelo mapa.\n");
            printf("2. Encontre monstros no mapa e entre na batalha com eles.\n");
            printf("3. Durante a batalha, escolha entre atacar ou fugir 1 ou 2, respectivamente.\n");
            printf("4. Ao derrotar um monstro, voc� ganha experi�ncia e pode obter recompensas.\n");
            printf("5. O jogo continua at� voc� atingir o n�vel m�ximo ou perder toda a sua sa�de.\n");
            quebrar;
        caso 'c':


         printf("Cr�ditos: Maria Eduarda A. Lopes, Antonio V., Jo�o Pedro \n");
         quebrar;
       caso 'd':
                //


          quebrar;


          caso 'q':
            printf("Saindo do jogo...\n");
            quebrar;
          padr�o:
            printf("Op��o invalida! Tente novamente.\n");
      }


    } while (menuChoice! = 'q');


    retornar 0;
}
