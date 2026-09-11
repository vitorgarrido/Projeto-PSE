# Projeto PSE

## Sistema de Planejamento e Acompanhamento de Ações do Programa Saúde na Escola

Projeto desenvolvido como parte da Atividade de Estudo Programado (AEP) do curso de Engenharia de Software da Unicesumar.

## Sobre o projeto

O projeto consiste no desenvolvimento de um sistema computacional introdutório em linguagem C para auxiliar no planejamento, registro e acompanhamento de ações coletivas do Programa Saúde na Escola (PSE).

O sistema utiliza somente dados fictícios e coletivos. Não armazena informações individuais ou sensíveis de estudantes e não realiza diagnóstico, triagem médica, prescrição ou recomendação de tratamento.

## Objetivo

Auxiliar na organização das ações do PSE por meio do cadastro, listagem, consulta e atualização de ações, registro da participação e geração de um resumo geral.

## Integrantes

- Juan Guimarães Mendonça
- Murilo Constancio Amadeu
- Vitor Garrido da Silva

## Tecnologias utilizadas

- Linguagem C
- GitHub
- Git
- Fluxogramas
- Pseudocódigo

## Funcionalidades

1. Cadastrar ação
2. Listar ações
3. Consultar ação pelo código
4. Atualizar situação
5. Registrar participação
6. Gerar resumo
0. Sair

## Como executar

O arquivo principal está em `src/sistema_pse.c`.

Com um compilador C instalado, por exemplo GCC:

```bash
gcc src/sistema_pse.c -o sistema_pse
./sistema_pse
```

No Windows, após compilar:

```text
sistema_pse.exe
```

## Estrutura do projeto

```text
Projeto-PSE/
├── README.md
├── documentacao/
│   ├── fluxogramas/
│   └── pseudocodigos/
├── src/
│   └── sistema_pse.c
└── testes/
    └── casos_de_teste.txt
```

## Documentação

A pasta `documentacao/` contém os materiais produzidos durante o desenvolvimento, incluindo fluxogramas e pseudocódigos.

## Testes

Os casos de teste estão em `testes/casos_de_teste.txt`.

## Projeto acadêmico

Este repositório foi desenvolvido para fins acadêmicos como parte das atividades do curso de Engenharia de Software da Unicesumar.
