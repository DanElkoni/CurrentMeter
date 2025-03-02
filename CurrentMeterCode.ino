float highRead;
float lowRead;

int onLed = 15;
int workingLed = 16;

int highCurr = 4;
int lowCurr = 5;

int start = 7;

bool working = false;

void setup() {
  // Serial Monitor
  Serial.begin(115200);
  
  // Indicator Lights
  pinMode(onLed, OUTPUT);
  digitalWrite(onLed, HIGH);
  pinMode(workingLed, OUTPUT);

  // Current Detection
  pinMode(highCurr, INPUT);
  pinMode(lowCurr, INPUT);

  // Start/Stop button
  pinMode(start, INPUT);
}

void loop() {
  if (digitalRead(start) == 1) {
    if (working) {
      working = false;
      Serial.println("Stop Recording");
      digitalWrite(workingLed, LOW);
      delay(500);
    }
    else {
      working = true;
      Serial.println("Start Recording");
      digitalWrite(workingLed, HIGH);
      delay(500);
    }
  }

  if (working) {
    //highRead = ((((float)analogRead(highCurr)/4096)*5*1.0456)-2.5)/.02267;
    //lowRead = ((((float)analogRead(lowCurr)/4096)*5*1.0456)-2.5)/.02267;
    highRead = (float)analogRead(highCurr);
    lowRead = (float)analogRead(lowCurr);
    Serial.print(112.28*log(lowRead)-853.19);Serial.print("#");
    Serial.print(.6151*highRead-1215.9);
    Serial.println();
  }
  delay(5);
}
