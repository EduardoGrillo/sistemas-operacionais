## Trabalho de Sistemas Operacionais - Processos e Threads.

<h4> Etapa 1: </h4> 

<p> Elaboração das tabelas hash para itens e classes. Dado uma linha do arquivo, considerar item as colunas de 0 a n - 1. Considere a coluna n de cada linha como classe. Nessas tabelas é preciso armazenar cada item como chave e seus índices no arquivo como valor. Considere como índice a linha que aquele valor específico aparece. Considere também item específico aquele item pertencente a coluna x. Logo, para itens de mesmo valor, a indexação deve ser feita de forma separada, ou seja, se um item aparece na coluna 1 e 3 com valor 23.4, considere como chave da hash (1, 23.4) e (3,23.4). Repita esse processo para as classes, armazenando como chave sua descrição e como valor suas indexações.</p>

# Compilação e Execução

O algoritmo disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:

<div>

| Comando                |  Função                                                                                           |
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

</div>

# Contato

<div>
<p align="justify"> Eduardo Grillo </p>
<a href="https://t.me/eduardogrilloo">
<img align="center" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
</div>
