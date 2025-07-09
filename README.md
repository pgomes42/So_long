# So_long "PAC-MAN"

<p align="center">
  <img src="assets/ele.gif" alt="Demonstração do Projeto" width="600"/>
</p>

Este projeto é uma versão personalizada do jogo *Pac-Man*, desenvolvida como parte do currículo da 42 Luanda.  
No modo bônus, há uma demonstração autêntica de **movimentação autônoma dos fantasmas**, o que adiciona desafio e dinamismo à jogabilidade.

---

## Objetivo do Jogo

Você controla o personagem principal (Pac-Man) e deve:
- Coletar todos os pontos no mapa (`C`)
- Evitar os fantasmas (`T`)
- Chegar à saída (`E`) **somente após coletar todos os pontos**

---

## Estrutura do Mapa

O mapa é carregado de um arquivo `.ber` e deve conter:
- `1`: parede (intransponível)
- `0`: caminho livre
- `P`: posição inicial do jogador
- `C`: coletável
- `E`: saída
- `T`: inimigo (modo bônus)

---

## Controles

| Tecla | Ação            |
|-------|-----------------|
| W     | Mover para cima |
| A     | Mover para esquerda |
| S     | Mover para baixo |
| D     | Mover para direita |
| ESC   | Sair do jogo    |

---

## Compilação

Clone o projeto e compile com `make`:

```bash
git clone https://github.com/pgomes42/So_long.git
cd So_long
make
```

---

## Execução

### Modo Normal
```bash
./so_long maps/valids/map_valid_0.ber
```

### Modo Bônus (com fantasmas)
```bash
./so_long_bonus maps/valids_bonus/map_valid_4.ber
```

---

## Estrutura do Projeto

```
So_long/
├── src/              # Código fonte principal
├── src_bonus/        # Código fonte do modo bônus
├── include/          # Headers
├── maps/             # Mapas do jogo
├── assets/           # Recursos gráficos
├── lib/              # Bibliotecas (libft, minilibx)
└── Makefile          # Compilação
```

---

## Características

- Interface gráfica usando MinilibX
- Movimentação suave do personagem
- Sistema de coleta de pontos
- Validação rigorosa de mapas
- Modo bônus com inimigos autônomos
- Animações e sprites customizados

---

## Dependências

- MinilibX (incluída no projeto)
- libft (incluída no projeto)
- CC
- Make

---

## Licença

Este projeto foi desenvolvido como parte do currículo da 42 Luanda.
