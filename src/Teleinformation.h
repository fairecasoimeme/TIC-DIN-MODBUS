bool bTranscodeCharTICStandard(unsigned int u16MaxLength, char *command, char *date, char *value,uint8_t *error, uint8_t *posFinal,byte u8Data, bool *lf);
bool bTranscodeCharTICHisto(unsigned int u16MaxLength, char *command, char *value, uint8_t *error,byte u8Data, bool *lf);
bool bDataProcessingStandard(char *au8Command,char *au8Value, uint8_t au8Pos);
bool bDataProcessingHisto(char *au8Command,char *au8Value, uint8_t au8Pos);