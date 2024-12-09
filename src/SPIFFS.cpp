#include <Arduino.h>
#include <ArduinoJson.h>
#include "FS.h"
#include "LittleFS.h"

bool config_write(String path, String key, String value)
{

  const char* prefix ="/config/";
  char name_with_extension[64];
  strcpy(name_with_extension,prefix);
  strcat(name_with_extension,path.c_str());
  File file = LittleFS.open(name_with_extension, FILE_READ);
  size_t filesize = file.size();

  DynamicJsonDocument doc(10000);

  if (filesize > 0)
  {
    DeserializationError error = deserializeJson(doc, file);
    if (error)
    {
      // DEBUG_PRINTLN(F("Erreur lors de la désérialisation du fichier"));
      file.close();
      return "Error";
    }
  }
  file.close();

  // Ajouter des valeurs dans le fichier json
  doc[key] = value;

  // serializeJsonPretty(doc, Serial);
  //  Écrire les données dans le fichier
  File tpFile = LittleFS.open(name_with_extension, "w+");
  if (!tpFile || tpFile.isDirectory())
  {
    Serial.print(F("Erreur lors de l'ouverture du fichier "));
    Serial.println(path);
    tpFile.close();
    return false;
  }

  if (!doc.isNull())
  {
    if (serializeJson(doc, tpFile) == 0)
    {
      Serial.println(F("Erreur lors de l'écriture dans le fichier"));
      tpFile.close();
      return false;
    }
  }

  // Fermer le fichier
  tpFile.close();
  return true;
  
}