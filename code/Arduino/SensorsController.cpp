#include "SensorsController.h"



SensorsController::SensorsController()
{
	countDistanceSensors = 5;
	countLineSensors = 5;
	minimalLineBound = 270;

	pinMode(constants.line_sensor_a_pin, OUTPUT);
	pinMode(constants.line_sensor_b_pin, OUTPUT);
	pinMode(constants.line_sensor_c_pin, OUTPUT);

	pinMode(constants.distance_sensor_a_pin, OUTPUT);
	pinMode(constants.distance_sensor_b_pin, OUTPUT);
	pinMode(constants.distance_sensor_c_pin, OUTPUT);

	digitalWrite(constants.line_sensor_a_pin, HIGH);
	digitalWrite(constants.line_sensor_b_pin, LOW);
	digitalWrite(constants.line_sensor_c_pin, HIGH);
}


void SensorsController::exec(ConnectingDevice *device, String command) {
	switch (command[1])
	{
	case distance_sensor_1:
		device->send(String(getDistance(1)));
		break;
	case distance_sensor_2:
		device->send(String(getDistance(2)));
		break;
	case distance_sensor_3:
		device->send(String(getDistance(3)));
		break;
	case distance_sensor_4:
		device->send(String(getDistance(4)));
		break;
	case distance_sensor_5:
		device->send(String(getDistance(5)));
		break;
	case distance_sensor_all:
		device->send(intArrayToString(getDistanceAll(), countDistanceSensors));
		break;
	case line_sensor_1:
		device->send(String(getLine(1)));
		break;
	case line_sensor_2:
		device->send(String(getLine(2)));
		break;
	case line_sensor_3:
		device->send(String(getLine(3)));
		break;
	case line_sensor_4:
		device->send(String(getLine(4)));
		break;
	case line_sensor_5:
		device->send(String(getLine(5)));
		break;
	case line_sensor_all:
		device->send(intArrayToString(getLineAll(), countLineSensors));
		break;
	default:
		break;
	}
}

String SensorsController::intArrayToString(int* array, int size) {
	String str = "";
	for (int i = 0; i < size; i++) {
		str += String(array[i]);
	}
	return str;
}

void SensorsController::chooseLineSensor(int number) {
	switch (number) {
		case 1:
			digitalWrite(constants.line_sensor_a_pin, LOW);
			digitalWrite(constants.line_sensor_b_pin, LOW);
			digitalWrite(constants.line_sensor_c_pin, HIGH);
			break;
		case 2:
			digitalWrite(constants.line_sensor_a_pin, HIGH);
			digitalWrite(constants.line_sensor_b_pin, HIGH);
			digitalWrite(constants.line_sensor_c_pin, HIGH);
			break;
		case 3:
			digitalWrite(constants.line_sensor_a_pin, HIGH);
			digitalWrite(constants.line_sensor_b_pin, LOW);
			digitalWrite(constants.line_sensor_c_pin, HIGH);
			break;
		case 4:
			digitalWrite(constants.line_sensor_a_pin, LOW);
			digitalWrite(constants.line_sensor_b_pin, HIGH);
			digitalWrite(constants.line_sensor_c_pin, HIGH);
			break;
		case 5:
			digitalWrite(constants.line_sensor_a_pin, HIGH);
			digitalWrite(constants.line_sensor_b_pin, LOW);
			digitalWrite(constants.line_sensor_c_pin, LOW);
			break;
		default: 
			break;
	}
}

int SensorsController::getLine(int number) {
	chooseLineSensor(number);
	return analogRead(A1) > minimalLineBound  ? 1 : 0;
}

int* SensorsController::getLineAll() {
	int* arr = new int[countLineSensors];
	for (int i = 0; i < countLineSensors; i++) {
		arr[i] = getLine(i + 1);
	}
	return arr;
}

void SensorsController::chooseDistanceSensor(int number) {
	switch (number) {
		case 1:
			digitalWrite(constants.distance_sensor_a_pin, HIGH);
			digitalWrite(constants.distance_sensor_b_pin, LOW);
			digitalWrite(constants.distance_sensor_c_pin, LOW);
			break;
		case 2:
			digitalWrite(constants.distance_sensor_a_pin, LOW);
			digitalWrite(constants.distance_sensor_b_pin, HIGH);
			digitalWrite(constants.distance_sensor_c_pin, HIGH);
			break;
		case 3: 
			digitalWrite(constants.distance_sensor_a_pin, LOW);
			digitalWrite(constants.distance_sensor_b_pin, LOW);
			digitalWrite(constants.distance_sensor_c_pin, HIGH);
			break;
		case 4: 
			digitalWrite(constants.distance_sensor_a_pin, HIGH);
			digitalWrite(constants.distance_sensor_b_pin, LOW);
			digitalWrite(constants.distance_sensor_c_pin, HIGH);
			break;
		case 5:
			digitalWrite(constants.distance_sensor_a_pin, HIGH);
			digitalWrite(constants.distance_sensor_b_pin, HIGH);
			digitalWrite(constants.distance_sensor_c_pin, HIGH);
			break;
		default: 
			break;
   }
}


int SensorsController::getDistance(int number) {
	chooseDistanceSensor(number);
	float volts = analogRead(A0);  
	float distance = (6762 / (volts)) - 4;
	return distance;
}

int* SensorsController::getDistanceAll() {
	int* arr = new int[countDistanceSensors];
	for (int i = 0; i < countDistanceSensors; i++) {
		arr[i] = getDistance(i + 1);
	}
	return arr;
}

int SensorsController::getAverageDistance(int number, int n) {
	int* arr = getDistanceNTime(number, n);
	int averageDistance = 0;
	for (int i = 0; i < n; i++) {
		averageDistance += arr[i];
	}
	return averageDistance / n;
}


int* SensorsController::getDistanceNTime(int number, int n) {
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = getDistance(number);
	}
	return arr;
}

SensorsController::~SensorsController()
{
}
