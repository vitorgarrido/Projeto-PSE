# PSE em Ação
## Sistema de Planejamento e Acompanhamento de Ações do Programa Saúde na Escola

### Sobre o projeto

O PSE em Ação é um sistema desenvolvido como projeto acadêmico do curso de Engenharia de Software da UNICESUMAR. Seu objetivo é auxiliar no planejamento, cadastro e acompanhamento de ações coletivas relacionadas ao Programa Saúde na Escola (PSE).

A aplicação permite organizar informações sobre atividades planejadas, realizadas e canceladas, facilitando o acompanhamento das ações e de seus resultados.

### Objetivo

Desenvolver um sistema em linguagem C que permita registrar e acompanhar ações do Programa Saúde na Escola, aplicando conceitos fundamentais de programação, como estruturas condicionais, estruturas de repetição, vetores, funções e manipulação de arquivos.

### Integrantes

- Juan Guimarães Mendonça
- Murilo Constancio Amadeu
- Vitor Garrido da Silva

### Tecnologias utilizadas

- Linguagem C
- Compilador GCC
- Git
- GitHub

### Funcionalidades

O sistema possui as seguintes funcionalidades:

1. Cadastrar ações.
2. Listar todas as ações.
3. Listar ações por situação.
4. Consultar ação pelo código.
5. Atualizar situação da ação.
6. Registrar participação.
7. Remover ação.
8. Gerar resumo geral.
9. Encerrar o programa.

### Informações cadastradas

Cada ação pode conter:

- Código identificador.
- Nome da ação.
- Escola.
- Tema.
- Data prevista.
- Público-alvo.
- Responsável.
- Quantidade de participantes previstos.
- Quantidade de participantes efetivos.
- Situação da ação.

### Situações disponíveis

- Planejada.
- Realizada.
- Cancelada.

### Como executar o projeto

É necessário possuir um compilador da linguagem C, como o GCC.

**1. Clone o repositório:**

```bash
git clone (https://github.com/vitorgarrido/Projeto-PSE/blob/main/README.md)
```

**2. Entre na pasta do projeto:**

```bash
cd Projeto-PSE
```

**3. Compile o programa:**

```bash
gcc src/sistema_pse.c -o sistema_pse
```

**4. Execute no Windows:**

```bash
.\sistema_pse.exe
```

**5. Execute no Linux:**

```bash
./sistema_pse
```

### Organização do repositório

- `documentacao/`: documentos e materiais do projeto.
- `documentacao/fluxogramas/`: representações visuais dos processos.
- `documentacao/pseudocodigos/`: algoritmos em pseudocódigo.
- `src/`: código-fonte do sistema.
- `testes/`: documentação dos casos de teste.

### Armazenamento de dados

O sistema utiliza estruturas de dados em memória durante a execução e também realiza a gravação dos registros em um arquivo local chamado `acoes.dat`, permitindo recuperar os dados em execuções posteriores.

### Privacidade e limitações

O projeto utiliza dados fictícios e coletivos. Não devem ser inseridos nomes de estudantes, documentos pessoais, diagnósticos ou informações clínicas.

A aplicação possui finalidade acadêmica e organizacional, não substituindo os profissionais envolvidos no Programa Saúde na Escola.

### Vídeo de apresentação

[Assista ao vídeo de apresentação do projeto](https://youtu.be/NokumxrBrP8?feature=shared)

### Instituição

UNICESUMAR — Centro Universitário de Maringá

Curso de Engenharia de Software

Maringá — Paraná

2026
