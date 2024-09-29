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


## Usar os Comandos Acesse o prompt de comando e utilize os seguintes comandos:

- touch nomeArquivo tamanho - Cria um arquivo.
- chmod nomeArquivo novasPermissoes - Altera as permissões do arquivo.
- ls - Lista arquivos no diretório atual.
- mkdir nomeDiretorio - Cria um diretório.
- link -h origem destino - Cria um link físico.
- link -s origem destino - Cria um link simbólico.
- df - Mostra espaço livre e ocupado.


## Contribuições
  Sinta-se à vontade para contribuir com melhorias ou sugestões!
