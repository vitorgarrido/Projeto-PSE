#include <stdio.h>
#include <string.h>

#define MAX_ACOES 100
#define TAM_TEXTO 100

typedef struct {
    int codigo;
    char nome[TAM_TEXTO];
    char escola[TAM_TEXTO];
    char tema[TAM_TEXTO];
    char data[TAM_TEXTO];
    char publicoAlvo[TAM_TEXTO];
    char responsavel[TAM_TEXTO];
    int participantesPrevistos;
    int participantesEfetivos;
    char situacao[20];
} Acao;

Acao acoes[MAX_ACOES];
int quantidadeAcoes = 0;

void limparEntrada(void);
void lerTexto(char texto[], int tamanho);
int lerInteiro(void);
void exibirMenu(void);
int buscarAcaoPorCodigo(int codigo);
void cadastrarAcao(void);
void listarAcoes(void);
void consultarAcao(void);
void atualizarSituacao(void);
void registrarParticipacao(void);
void gerarResumo(void);
void exibirAcao(Acao acao);

void limparEntrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void lerTexto(char texto[], int tamanho) {
    if (fgets(texto, tamanho, stdin) != NULL) {
        texto[strcspn(texto, "\n")] = '\0';
    }
}

int lerInteiro(void) {
    int valor;
    while (scanf("%d", &valor) != 1) {
        printf("Entrada invalida. Digite um numero: ");
        limparEntrada();
    }
    limparEntrada();
    return valor;
}

void exibirMenu(void) {
    printf("\n========================================\n");
    printf("       SISTEMA PSE - SAUDE NA ESCOLA\n");
    printf("========================================\n");
    printf("1 - Cadastrar acao\n");
    printf("2 - Listar acoes\n");
    printf("3 - Consultar acao\n");
    printf("4 - Atualizar situacao\n");
    printf("5 - Registrar participacao\n");
    printf("6 - Gerar resumo\n");
    printf("0 - Sair\n");
    printf("========================================\n");
}

int buscarAcaoPorCodigo(int codigo) {
    int i;
    for (i = 0; i < quantidadeAcoes; i++) {
        if (acoes[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

void exibirAcao(Acao acao) {
    printf("\n----------------------------------------\n");
    printf("Codigo: %03d\n", acao.codigo);
    printf("Nome da acao: %s\n", acao.nome);
    printf("Escola: %s\n", acao.escola);
    printf("Tema: %s\n", acao.tema);
    printf("Data prevista: %s\n", acao.data);
    printf("Publico-alvo: %s\n", acao.publicoAlvo);
    printf("Responsavel: %s\n", acao.responsavel);
    printf("Participantes previstos: %d\n", acao.participantesPrevistos);
    printf("Participantes efetivos: %d\n", acao.participantesEfetivos);
    printf("Situacao: %s\n", acao.situacao);
    printf("----------------------------------------\n");
}

void cadastrarAcao(void) {
    Acao nova;

    if (quantidadeAcoes >= MAX_ACOES) {
        printf("\nLimite de acoes atingido.\n");
        return;
    }

    printf("\n=== CADASTRO DE ACAO ===\n");

    printf("Digite o codigo: ");
    nova.codigo = lerInteiro();

    if (nova.codigo <= 0) {
        printf("Codigo invalido. O codigo deve ser positivo.\n");
        return;
    }

    if (buscarAcaoPorCodigo(nova.codigo) != -1) {
        printf("Codigo ja cadastrado.\n");
        return;
    }

    printf("Nome da acao: ");
    lerTexto(nova.nome, TAM_TEXTO);

    printf("Escola: ");
    lerTexto(nova.escola, TAM_TEXTO);

    printf("Tema: ");
    lerTexto(nova.tema, TAM_TEXTO);

    printf("Data prevista: ");
    lerTexto(nova.data, TAM_TEXTO);

    printf("Publico-alvo: ");
    lerTexto(nova.publicoAlvo, TAM_TEXTO);

    printf("Responsavel: ");
    lerTexto(nova.responsavel, TAM_TEXTO);

    printf("Quantidade prevista de participantes: ");
    nova.participantesPrevistos = lerInteiro();

    if (nova.participantesPrevistos < 0) {
        printf("Quantidade invalida. O valor nao pode ser negativo.\n");
        return;
    }

    nova.participantesEfetivos = 0;
    strcpy(nova.situacao, "Planejada");

    acoes[quantidadeAcoes] = nova;
    quantidadeAcoes++;

    printf("\nAcao cadastrada com sucesso!\n");
}

void listarAcoes(void) {
    int i;

    if (quantidadeAcoes == 0) {
        printf("\nNenhuma acao cadastrada.\n");
        return;
    }

    printf("\n=== LISTA DE ACOES ===\n");

    for (i = 0; i < quantidadeAcoes; i++) {
        exibirAcao(acoes[i]);
    }
}

void consultarAcao(void) {
    int codigo;
    int indice;

    printf("\n=== CONSULTAR ACAO ===\n");
    printf("Digite o codigo da acao: ");
    codigo = lerInteiro();

    indice = buscarAcaoPorCodigo(codigo);

    if (indice == -1) {
        printf("Acao nao encontrada.\n");
        return;
    }

    exibirAcao(acoes[indice]);
}

void atualizarSituacao(void) {
    int codigo;
    int indice;
    int opcao;

    printf("\n=== ATUALIZAR SITUACAO ===\n");
    printf("Digite o codigo da acao: ");
    codigo = lerInteiro();

    indice = buscarAcaoPorCodigo(codigo);

    if (indice == -1) {
        printf("Acao nao encontrada.\n");
        return;
    }

    printf("\nSituacao atual: %s\n", acoes[indice].situacao);
    printf("1 - Planejada\n");
    printf("2 - Realizada\n");
    printf("3 - Cancelada\n");
    printf("Escolha a nova situacao: ");
    opcao = lerInteiro();

    switch (opcao) {
        case 1:
            strcpy(acoes[indice].situacao, "Planejada");
            printf("Situacao atualizada para Planejada.\n");
            break;
        case 2:
            strcpy(acoes[indice].situacao, "Realizada");
            printf("Situacao atualizada para Realizada.\n");
            break;
        case 3:
            strcpy(acoes[indice].situacao, "Cancelada");
            printf("Situacao atualizada para Cancelada.\n");
            break;
        default:
            printf("Opcao de situacao invalida.\n");
    }
}

void registrarParticipacao(void) {
    int codigo;
    int indice;
    int participantes;

    printf("\n=== REGISTRAR PARTICIPACAO ===\n");
    printf("Digite o codigo da acao: ");
    codigo = lerInteiro();

    indice = buscarAcaoPorCodigo(codigo);

    if (indice == -1) {
        printf("Acao nao encontrada.\n");
        return;
    }

    if (strcmp(acoes[indice].situacao, "Realizada") != 0) {
        printf("A participacao somente pode ser registrada para uma acao realizada.\n");
        return;
    }

    printf("Quantidade prevista: %d\n", acoes[indice].participantesPrevistos);
    printf("Quantidade efetiva de participantes: ");
    participantes = lerInteiro();

    if (participantes < 0) {
        printf("Quantidade invalida. O valor nao pode ser negativo.\n");
        return;
    }

    acoes[indice].participantesEfetivos = participantes;

    printf("Participacao registrada com sucesso!\n");
}

void gerarResumo(void) {
    int i;
    int planejadas = 0;
    int realizadas = 0;
    int canceladas = 0;
    int totalPrevistos = 0;
    int totalEfetivos = 0;
    double percentual;

    for (i = 0; i < quantidadeAcoes; i++) {
        totalPrevistos += acoes[i].participantesPrevistos;
        totalEfetivos += acoes[i].participantesEfetivos;

        if (strcmp(acoes[i].situacao, "Planejada") == 0) {
            planejadas++;
        } else if (strcmp(acoes[i].situacao, "Realizada") == 0) {
            realizadas++;
        } else if (strcmp(acoes[i].situacao, "Cancelada") == 0) {
            canceladas++;
        }
    }

    if (totalPrevistos > 0) {
        percentual = ((double) totalEfetivos / totalPrevistos) * 100.0;
    } else {
        percentual = 0.0;
    }

    printf("\n=== RESUMO GERAL ===\n");
    printf("Quantidade de acoes: %d\n", quantidadeAcoes);
    printf("Acoes planejadas: %d\n", planejadas);
    printf("Acoes realizadas: %d\n", realizadas);
    printf("Acoes canceladas: %d\n", canceladas);
    printf("Total de participantes previstos: %d\n", totalPrevistos);
    printf("Total de participantes efetivos: %d\n", totalEfetivos);
    printf("Percentual de participacao: %.2f%%\n", percentual);
}

int main(void) {
    int opcao;

    do {
        exibirMenu();
        printf("Digite uma opcao: ");
        opcao = lerInteiro();

        switch (opcao) {
            case 1:
                cadastrarAcao();
                break;
            case 2:
                listarAcoes();
                break;
            case 3:
                consultarAcao();
                break;
            case 4:
                atualizarSituacao();
                break;
            case 5:
                registrarParticipacao();
                break;
            case 6:
                gerarResumo();
                break;
            case 0:
                printf("\nPrograma encerrado.\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
