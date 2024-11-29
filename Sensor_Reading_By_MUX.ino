// Define control pins for the multiplexer
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define SIG_PIN A0 // Define the signal pin connected to the multiplexer (SIG)

int sensor[12];

void setup() {
  // Set control pins as outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  for (int channel = 0; channel < 15; channel++) {
    selectChannel(channel);
    sensor[channel] = analogRead(SIG_PIN);
    Serial.print(String(sensor[channel]) + "  ");  //comment this line while using in main LFR code
  }
  Serial.println();
}

// Function to select a channel on the multiplexer
void selectChannel(int channel) {
  // Set the state of each control pin
  digitalWrite(S0, bitRead(channel, 0));  // Least significant bit
  digitalWrite(S1, bitRead(channel, 1));
  digitalWrite(S2, bitRead(channel, 2));
  digitalWrite(S3, bitRead(channel, 3));  // Most significant bit
}

