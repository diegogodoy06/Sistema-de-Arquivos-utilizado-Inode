#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BLOCO_TAMANHO 10
#define MAX_BLOCOS 1000
#define INODES_MAX 100
#define PONTEIROS_DIRETOS 5

// Estrutura de inode
typedef struct {
    int tamanho;
    int blocos_diretos[PONTEIROS_DIRETOS];
    int bloco_indireto_simples;
    int bloco_indireto_duplo;
    int bloco_indireto_triplo;
    char data[20];
    char permissao[10];
    int tipo;  // 0 = Arquivo, 1 = Diretório
} Inode;

// Estrutura do sistema de arquivos
typedef struct {
    Inode inodes[INODES_MAX];
    char blocos[MAX_BLOCOS][BLOCO_TAMANHO];
    int blocos_livres[MAX_BLOCOS];
} SistemaDeArquivos;

SistemaDeArquivos fs;

// Função para inicializar o sistema de arquivos
void inicializar_fs() {
    for (int i = 0; i < MAX_BLOCOS; i++) {
        fs.blocos_livres[i] = 1;  // 1 significa bloco livre
    }
    for (int i = 0; i < INODES_MAX; i++) {
        fs.inodes[i].tamanho = 0;
        fs.inodes[i].bloco_indireto_simples = -1;
        fs.inodes[i].bloco_indireto_duplo = -1;
        fs.inodes[i].bloco_indireto_triplo = -1;
        strcpy(fs.inodes[i].permissao, "rwxrwxrwx");  // Padrão de permissões
    }
}

// Função para alocar blocos livres
int alocar_bloco() {
    for (int i = 0; i < MAX_BLOCOS; i++) {
        if (fs.blocos_livres[i] == 1) {
            fs.blocos_livres[i] = 0;  // Marcando como ocupado
            return i;
        }
    }
    return -1;  // Sem blocos disponíveis
}

// Função para criar um inode para um arquivo
int criar_arquivo(int tamanho, char *permissao, int tipo) {
    for (int i = 0; i < INODES_MAX; i++) {
        if (fs.inodes[i].tamanho == 0) {  // Inode disponível
            fs.inodes[i].tamanho = tamanho;
            strcpy(fs.inodes[i].permissao, permissao);
            fs.inodes[i].tipo = tipo;
            
            time_t agora = time(NULL);
            strftime(fs.inodes[i].data, 20, "%Y-%m-%d %H:%M", localtime(&agora));
            
            int blocos_necessarios = (tamanho + BLOCO_TAMANHO - 1) / BLOCO_TAMANHO;
            
            // Alocando blocos diretos
            for (int j = 0; j < PONTEIROS_DIRETOS && blocos_necessarios > 0; j++, blocos_necessarios--) {
                fs.inodes[i].blocos_diretos[j] = alocar_bloco();
            }
            
            // Se necessário, alocar blocos indiretos
            if (blocos_necessarios > 0) {
                fs.inodes[i].bloco_indireto_simples = alocar_bloco();
                // Implementação para indiretos duplos e triplos pode ser adicionada aqui
            }

            return i;  // Retorna o número do inode criado
        }
    }
    return -1;  // Sem inodes disponíveis
}

// Função para listar inodes
void listar_inodes() {
    for (int i = 0; i < INODES_MAX; i++) {
        if (fs.inodes[i].tamanho > 0) {
            printf("Inode %d: Tamanho: %d bytes, Permissões: %s, Data: %s, Tipo: %s\n", 
                i, fs.inodes[i].tamanho, fs.inodes[i].permissao, fs.inodes[i].data,
                fs.inodes[i].tipo == 0 ? "Arquivo" : "Diretório");
        }
    }
}

int main() {
    inicializar_fs();
    
    // Exemplo: criar um arquivo de 60 bytes
    criar_arquivo(60, "rwxr--r--", 0);
    
    // Exemplo: listar inodes
    listar_inodes();
    
    return 0;
}
