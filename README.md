# TP_micro_S10_MONNIER_CROCE

## 1. Démarrage

1. Créer un projet pour la carte **NUCLEO_L476RG**.
2. Initialiser les périphériques en mode par défaut (ne pas activer la BSP).
3. Tester la LED **LD2**.
4. Tester l'**USART2** connecté à la **STLink interne**.
    ```c
      int __io_putchar(int ch) {
          HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
          return ch;
      }    
6. Faire fonctionner la fonction `printf`.
     ```c
      printf("nathan monnier \r\n");

---

## 2. Le GPIO Expander et le VU-Metre

### 2.1 Configuration
- Identifier la référence du **GPIO Expander** et télécharger sa datasheet.
   - Référence MCP23S17-E/SO : [MCP23S17-E_SO.pdf](https://github.com/MonnierNathan/TP_micro_S10_MONNIER_CROCE/blob/master/MCP23S17-E_SO.pdf)
- Déterminer quel **SPI** est utilisé sur le **STM32**.
   - Le SPI utilisé sur le STM est le **SPI3**
- Configurer les paramètres correspondants dans **STM32CubeIDE**.
   - ![IMG](https://github.com/MonnierNathan/TP_micro_S10_MONNIER_CROCE/blob/master/Images/configSPI3.png "configSPI3")   

### 2.2 Tests
- Faire clignoter une ou plusieurs **LED**.
   - ```c
     HAL_GPIO_ToggelPIN(GPIOA,GPIO_PIN_5);
     HAL_Delay(5000);
- Tester toutes les LED avec un **chenillard**.
  ```c
    for(int i=1; i<=8;i++)
    {
        val = val<<1;
        printf("val = %d", val);
        MCP23S17_WriteRegister(0x12, val);
        MCP23S17_WriteRegister(0x13, val);
        HAL_Delay(500);
        if (i==8)
        {
            val=0xFF;
            MCP23S17_WriteRegister(0x12, val);
            MCP23S17_WriteRegister(0x13, val);
        }
    }
![vidéo Chenillard](https://github.com/MonnierNathan/TP_micro_S10_MONNIER_CROCE/blob/master/video/VID_20250321_143431.mp4)

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
  ![clkI2C](https://github.com/MonnierNathan/TP_micro_S10_MONNIER_CROCE/blob/master/Images/SDS00001.BMP "clkI2C")
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

