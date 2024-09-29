# Simulação de Sistema de Arquivos com Inodes

Este projeto é uma simulação de um sistema de arquivos que utiliza inodes para gerenciar arquivos e diretórios. Ele foi desenvolvido como parte de uma atividade acadêmica para a disciplina de Sistemas Operacionais.

## Funcionalidades

- **Gerenciamento de Arquivos e Diretórios**
  - Criar, visualizar e deletar arquivos e diretórios.
  - Alterar permissões de acesso (chmod).
  - Navegar entre diretórios (cd, ls, ls -l).
  
- **Links**
  - Criar links físicos e simbólicos.
  - Remover links.

- **Gerenciamento de Blocos**
  - Marcar blocos como defeituosos (bad).
  - Exibir espaço livre e ocupado no disco (df).

## Estrutura de Dados

O sistema de arquivos utiliza as seguintes estruturas:

- **Inode**: Representa um arquivo ou diretório, contendo informações como tamanho, permissões, e ponteiros para os blocos de dados.
- **Blocos**: O disco é dividido em blocos de 10 bytes, totalizando 1000 blocos.

## Como Usar

1. **Compilar o Código**
   Utilize um compilador C (como `gcc`) para compilar o arquivo:
   ```bash
   gcc -o sistema_arquivos sistema_arquivos.c
