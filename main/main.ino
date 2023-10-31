// ----- KEYPAD -----
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;
const char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

const byte rowPins[ROWS] = {10, 9, 8, 7};
const byte colPins[COLS] = {6, 5, 4, 3};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// ----- OUTPUTS -----
const int o[] = {13, 12, 11, 2};

bool oState[] = {false, false, false};

// ----- PAGES -----
int page = 0;

// ----- SERIAL -----
bool connection = false;

// ----- SETUP -----
void setup()
{
  Serial.begin(9600);

  for (int i = 0; i <= 3; i++)
  {
    pinMode(o[i], OUTPUT);
    digitalWrite(o[i], 0);
  }
}

// ----- LOOP -----
void loop()
{
  while (connection == false)
  {
    digitalWrite(o[3], 1);
    delay(500);
    digitalWrite(o[3], 0);
    delay(500);

    if (Serial.available() > 0)
    {
      digitalWrite(o[3], 0);
      delay(500);
      char data = Serial.read();

      if (data == 'i')
      {
        digitalWrite(o[3], 1);
        delay(500);
        digitalWrite(o[3], 0);
        delay(100);
        digitalWrite(o[3], 1);
        delay(100);
        digitalWrite(o[3], 0);
        connection = true;
      }
    }
  }

  char key = keypad.getKey();

  if (key)
  {
    if (key == 'A')
    {
      page = 0;
    }
    else if (key == 'B')
    {
      page = 1;
    }
    else if (key == 'C')
    {
      page = 2;
    }
    else if (key == 'D')
    {
      page = 3;
    }
    else
    {
      if (page == 0)
      {
        switch (key)
        {
        case '1':
          Serial.println("arc");
          break;

        case '2':
          Serial.println("system_preferences");
          break;

        case '3':
          Serial.println("spark");
          break;

        case '4':
          Serial.println("messages");
          break;

        case '5':
          Serial.println("music");
          break;

        case '6':
          Serial.println("photos");
          break;

        case '7':
          Serial.println("reminders");
          break;

        case '8':
          Serial.println("calendar");
          break;

        case '9':
          Serial.println("discord");
          break;

        case '0':
          Serial.println("remarkable");
          break;
        }
      }

      if (page == 1)
      {
        switch (key)
        {
        case '1':
          Serial.println("iterm");
          break;

        case '2':
          Serial.println("vscode");
          break;

        case '3':
          Serial.println("source_tree");
          break;

        case '4':
          Serial.println("arduino");
          break;

        case '5':
          Serial.println("textmate");
          break;

        case '6':
          Serial.println("termius");
          break;

        case '7':
          Serial.println("postman");
          break;

        case '8':
          Serial.println("devdocs");
          break;

        case '9':
          Serial.println("diskutility");
          break;

        case '0':
          Serial.println("resmon");
          break;
        }
      }

      if (page == 2)
      {
        switch (key)
        {
        case '1':
          Serial.println("speedtest");
          break;

        case '2':
          break;

        case '3':
          Serial.println("myip");
          break;

        case '4':
          Serial.println("clear");
          break;

        case '5':
          Serial.println("lock");
          break;

        case '6':

          break;

        case '7':

          break;

        case '8':

          break;

        case '9':

          break;

        case '0':
          Serial.println("disconnect");
          connection = false;
          break;
        }
      }

      if (page == 3)
      {
        switch (key)
        {
        case '1':
          if (oState[0] == false)
          {
            digitalWrite(o[0], 1);
            oState[0] = true;
          }
          else
          {
            digitalWrite(o[0], 0);
            oState[0] = false;
          }
          break;

        case '2':
          if (oState[1] == false)
          {
            digitalWrite(o[1], 1);
            oState[1] = true;
          }
          else
          {
            digitalWrite(o[1], 0);
            oState[1] = false;
          }
          break;

        case '3':
          if (oState[2] == false)
          {
            digitalWrite(o[2], 1);
            oState[2] = true;
          }
          else
          {
            digitalWrite(o[2], 0);
            oState[2] = false;
          }
          break;

        case '4':

          break;

        case '5':

          break;

        case '6':

          break;

        case '7':

          break;

        case '8':

          break;

        case '9':

          break;

        case '0':

          break;
        }
      }
    }
  }
}
