# TP_micro_S10_MONNIER_CROCE

## 1. Démarrage

1. Créer un projet pour la carte **NUCLEO_L476RG**.
2. Initialiser les périphériques en mode par défaut (ne pas activer la BSP).
3. Tester la LED **LD2**.
4. Tester l'**USART2** connecté à la **STLink interne**.
5. Faire fonctionner la fonction `printf`.

---

## 2. Le GPIO Expander et le VU-Metre

### 2.1 Configuration
- Identifier la référence du **GPIO Expander** et télécharger sa datasheet.
   - Référence MCP23S17-E/SO : [MCP23S17-E_SO.pdf](https://github.com/MonnierNathan/TP_micro_S10_MONNIER_CROCE/blob/main/MCP23S17-E_SO.pdf)
- Déterminer quel **SPI** est utilisé sur le **STM32**.
   - Le SPI utilisé sur le STM est le **SPI3**
- Configurer les paramètres correspondants dans **STM32CubeIDE**.

### 2.2 Tests
- Faire clignoter une ou plusieurs **LED**.
- Tester toutes les LED avec un **chenillard**.

### 2.3 Driver
- Écrire un **driver** pour piloter les LED.
- Écrire une **fonction shell** permettant d'allumer ou d'éteindre une LED.

---

## 3. Le CODEC Audio SGTL5000

### 3.1 Configuration Préalable
- Configurer les protocoles **I2C** et **I2S (SAI)** via **STM32CubeIDE**.
- Configurer les pins et les **blocs SAI**.
- Activer le **DMA** pour **SAI A** et **SAI B**.
- Ajouter `__HAL_SAI_ENABLE(&hsai_BlockA2);` dans la `main()`.

### 3.2 Configuration du CODEC par l'I2C
- Vérifier la présence d'une horloge sur **MCLK**.
- Lire et configurer les registres du **SGTL5000**.

### 3.3 Signaux I2S
- Démarrer la réception et la transmission en **DMA**.
- Observer les signaux d'horloge à l'oscilloscope.

### 3.4 Génération de Signal Audio
- Générer un **signal triangulaire** et le vérifier à l'oscilloscope.

### 3.5 Bypass Numérique
- Lire les échantillons de l'**ADC** et les envoyer au **DAC**.

---

## 4. Visualisation
- Afficher le volume sonore sur les LED (**VU-mètre**).

---

## 5. Filtre RC
- Implémenter l'équation différentielle du filtre **RC**.
- Calculer et programmer les coefficients **A, B et D**.
- Implémenter la fonction `RC_filter_update`.

---

## 6. Programmation d'un Effet Audio
- Implémenter un des effets suivants :
  - Saturation/Distortion
  - Tremolo
  - Filtre analogique
  - Delay
  - Chorus/Phaser/Flanger
  - Compresseur
  - Reverb

