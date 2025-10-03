int main(void) {
    // --------- Carta 1 ----------
    char estado1;
    char codigo1[4];
    char cidade1[50];
    unsigned long int populacao1;     // Nível Mestre pede esse tipo
    float area1;
    float pib1;                       // em bilhões
    int pontos1;
    float densidade1, pibPerCapita1, super1;

    // --------- Carta 2 ----------
    char estado2;
    char codigo2[4];
    char cidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;                       // em bilhões
    int pontos2;
    float densidade2, pibPerCapita2, super2;

    // ===== Entrada dos dados da Carta 1 =====
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Digite o estado (A-H): ");
    scanf(" %c", &estado1);
    while (getchar() != '\n'); // limpa o '\n' pendente

    printf("Digite o código da carta (ex: A01): ");
    scanf(" %3s", codigo1);    // limita a 3 chars + '\0'

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", cidade1); // lê linha com espaços

    printf("Digite a população: ");
    scanf("%lu", &populacao1); // %lu para unsigned long

    printf("Digite a área (km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &pib1);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontos1);

    // ===== Cálculos Carta 1 =====
    densidade1    = (float)populacao1 / area1;                     // hab/km²
    pibPerCapita1 = (pib1 * 1000000000.0f) / (float)populacao1;    // PIB está em bilhões
    super1 = (float)populacao1
           + area1
           + (pib1 * 1000000000.0f)
           + (float)pontos1
           + pibPerCapita1
           + (1.0f / densidade1); // inverso da densidade

    // ===== Entrada dos dados da Carta 2 =====
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Digite o estado (A-H): ");
    scanf(" %c", &estado2);
    while (getchar() != '\n');

    printf("Digite o código da carta (ex: B02): ");
    scanf(" %3s", codigo2);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", cidade2);

    printf("Digite a população: ");
    scanf("%lu", &populacao2);

    printf("Digite a área (km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &pib2);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontos2);

    // ===== Cálculos Carta 2 =====
    densidade2    = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000.0f) / (float)populacao2;
    super2 = (float)populacao2
           + area2
           + (pib2 * 1000000000.0f)
           + (float)pontos2
           + pibPerCapita2
           + (1.0f / densidade2);

    // ===== Exibição (opcional) =====
    printf("\n=== Carta 1 ===\n");
    printf("Estado: %c\nCódigo: %s\nCidade: %s\n", estado1, codigo1, cidade1);
    printf("População: %lu\nÁrea: %.2f km²\nPIB: %.2f bilhões\nPontos: %d\n",
           populacao1, area1, pib1, pontos1);
    printf("Densidade: %.2f hab/km²\nPIB per Capita: %.2f\nSuper Poder: %.2f\n",
           densidade1, pibPerCapita1, super1);

    printf("\n=== Carta 2 ===\n");
    printf("Estado: %c\nCódigo: %s\nCidade: %s\n", estado2, codigo2, cidade2);
    printf("População: %lu\nÁrea: %.2f km²\nPIB: %.2f bilhões\nPontos: %d\n",
           populacao2, area2, pib2, pontos2);
    printf("Densidade: %.2f hab/km²\nPIB per Capita: %.2f\nSuper Poder: %.2f\n",
           densidade2, pibPerCapita2, super2);

    // ===== Comparações (sem if/else; só operadores relacionais) =====
    // Para densidade: vence o MENOR valor. Para o resto (inclui Super): vence o MAIOR.
    int vPop   = (populacao1    > populacao2);
    int vArea  = (area1         > area2);
    int vPib   = (pib1          > pib2);
    int vPts   = (pontos1       > pontos2);
    int vDens  = (densidade1    < densidade2); // menor vence
    int vPpc   = (pibPerCapita1 > pibPerCapita2);
    int vSuper = (super1        > super2);

    printf("\n=== Comparação de Cartas ===\n");
    printf("População: Carta %d venceu (%d)\n",            vPop   ? 1 : 2, vPop);
    printf("Área: Carta %d venceu (%d)\n",                 vArea  ? 1 : 2, vArea);
    printf("PIB: Carta %d venceu (%d)\n",                  vPib   ? 1 : 2, vPib);
    printf("Pontos Turísticos: Carta %d venceu (%d)\n",    vPts   ? 1 : 2, vPts);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", vDens ? 1 : 2, vDens);
    printf("PIB per Capita: Carta %d venceu (%d)\n",       vPpc   ? 1 : 2, vPpc);
    printf("Super Poder: Carta %d venceu (%d)\n",          vSuper ? 1 : 2, vSuper);

    return 0;
}
