/*
 * Modes
 * -----
 *   List of modes that the system can be in.
 */
const int kNormal = 0;
const int kNoConnection = 1;

int currentMode = kNormal;

/*
 * Exceptions
 * ----------
 *   List of exceptions that the system has to handle.
 *   When 0, exception has not been raised, otherwise exception has been raised.
 */
int handling_LEDFailureRaisedInTurnOnSmartLightDevice_event = 0;
int handling_WiFiLEDFailureRaisedInTurnOnSmartLightDevice_event = 0;
int handling_ErrorDisplayFailureRaisedInTurnOnSmartLightDevice_event = 0;
int handling_LEDFailureRaisedInDebugHardware_event = 0;
int handling_WiFiLEDFailureRaisedInDebugHardware_event = 0;
int handling_ErrorDisplayFailureRaisedInDebugHardware_event = 0;
int handling_WiFiUnreachableRaisedInViewSmartLightDeviceStatus_event = 0;
int handling_WiFiUnreachableRaisedInRecordData_event = 0;

/*
 * Operations - LED
 * ----------
 *   List of operations that the system can be invoke on the LED.
 */
const int kLED_LEDTurnOn = 0;
const int kLED_LEDTurnOff = 1;

/*
 * Operations - LDR
 * ----------
 *   List of operations that the system can be invoke on the LDR.
 */
const int kLDR_LDRMonitored = 2;

/*
 * Operations - DebugButton
 * ----------
 *   List of operations that the system can be invoke on the DebugButton.
 */
const int kDebugButton_DebugButtonMonitored = 3;

/*
 * Operations - WiFiLED
 * ----------
 *   List of operations that the system can be invoke on the WiFiLED.
 */
const int kWiFiLED_WiFiLEDTurnOn = 4;
const int kWiFiLED_WiFiLEDTurnOff = 5;

/*
 * Operations - ErrorDisplay
 * ----------
 *   List of operations that the system can be invoke on the ErrorDisplay.
 */
const int kErrorDisplay_ErrorDisplayShowNormalModeCode = 6;
const int kErrorDisplay_ErrorDisplayShowNoConnectionModeCode = 7;


/*
 * Function List.
 */
void interactWithBoard();
void interactWithBoardDefault();
void interactWithBoardInNormalMode();
void interactWithBoardInNoConnectionMode();
void UseSmartLightsView_Behaviour();
void operateBoard();
void operateBoardDefault();
void operateBoardInNormalMode();
void operateBoardInNoConnectionMode();
void OperateSmartLightsView_Behaviour();
void updateLED(int val);
void updateLDR(int val);
void updateDebugButton(int val);
void updateWiFiLED(int val);
void updateErrorDisplay(int val);
void DisplayErrorCodeHandler();
int attempt_DisplayErrorCodeHandler();
void ReconnectDeviceHandler();
int attempt_ReconnectDeviceHandler();
void RepairDeviceHandler();
int attempt_RepairDeviceHandler();
void UseSmartLightsBehaviour_Behaviour_Impl();
void TurnOnSmartLightDevice_Behaviour_Impl();
void ViewSmartLightDeviceStatus_Behaviour_Impl();
void DebugHardware_Behaviour_Impl();
void ViewLogs_Behaviour_Impl();
void TurnOffSmartLightDevice_Behaviour_Impl();
void OperateSmartLightsBehaviour_Behaviour_Impl();
void ManageLED_Behaviour_Impl();
void RecordData_Behaviour_Impl();
void DisplayErrorCodeBehaviour_Behaviour_Impl();
void ReconnectDeviceBehaviour_Behaviour_Impl();
void RepairDeviceBehaviour_Behaviour_Impl();

/*
 * Function: interactWithBoard
 * ---------------------------
 *   Non-device behaviour with board (external).
 */
void interactWithBoard() {
	switch (currentMode) {
	  case kNormal:
	    interactWithBoardInNormalMode();
	    break;
	  case kNoConnection:
	    interactWithBoardInNoConnectionMode();
	    break;
	  default:
	    interactWithBoardDefault();
	    break;
	}
}

/*
 * Function: interactWithBoardDefault
 */
void interactWithBoardDefault() {
	UseSmartLightsView_Behaviour();
}

/*
 * Function: interactWithBoardInNormalMode
 */
void interactWithBoardInNormalMode() {
	// Insert Code Below
	interactWithBoardDefault();
	// Insert Code Above
}

/*
 * Function: interactWithBoardInNoConnectionMode
 */
void interactWithBoardInNoConnectionMode() {
	// Insert Code Below
	interactWithBoardDefault();
	// Insert Code Above
}


/*
 * Function UseSmartLightsView_Behaviour
 */
void UseSmartLightsView_Behaviour() {
	if ((handling_LEDFailureRaisedInTurnOnSmartLightDevice_event != 0) || (handling_WiFiLEDFailureRaisedInTurnOnSmartLightDevice_event != 0) || (handling_ErrorDisplayFailureRaisedInTurnOnSmartLightDevice_event != 0) || (handling_LEDFailureRaisedInDebugHardware_event != 0) || (handling_WiFiLEDFailureRaisedInDebugHardware_event != 0) || (handling_ErrorDisplayFailureRaisedInDebugHardware_event != 0) || (handling_WiFiUnreachableRaisedInViewSmartLightDeviceStatus_event != 0) || (handling_WiFiUnreachableRaisedInRecordData_event != 0) ||  false) {
		return;
	}
	UseSmartLightsBehaviour_Behaviour_Impl();
}

void UseSmartLightsBehaviour_Behaviour_Impl() {
	// Insert Code Below
	TurnOnSmartLightDevice_Behaviour_Impl();
	ViewSmartLightDeviceStatus_Behaviour_Impl();
	DebugHardware_Behaviour_Impl();
	ViewLogs_Behaviour_Impl();
	TurnOffSmartLightDevice_Behaviour_Impl();
	// Finished
	// Insert Code Above
}

void TurnOnSmartLightDevice_Behaviour_Impl() {
	// Insert Code Below
	// TheSystemInitializesConnectionToTheLEDWiFiLEDAndErrorDisplay
	// DecideAfterTheSystemInitializesConnectionToTheLEDWiFiLEDAndErrorDisplay
	// TheSystemInstructsTheLEDToBlink
	for (int i = 0; i < 3; i++) {
	    updateLED(kLED_LEDTurnOn);
	    delay(200);
	
	    updateLED(kLED_LEDTurnOff);
	    delay(200);
	  }
	// DecideAfterTheSystemInstructsTheLEDToBlink
	// TheSystemInstructsTheWiFiLEDToBlink
	for (int i = 0; i < 3; i++) {
	    updateWiFiLED(kWiFiLED_WiFiLEDTurnOn);
	    delay(200);
	
	    updateWiFiLED(kWiFiLED_WiFiLEDTurnOff);
	    delay(200);
	  }
	// DecideAfterTheSystemInstructsTheWiFiLEDToBlink
	// TheSystemInstructsTheErrorDisplayToBlink
	for (int i = 0; i < 3; i++) {
	    updateErrorDisplay(kErrorDisplay_ErrorDisplayShowNormalModeCode);
	    delay(200);
	
	    updateErrorDisplay(kErrorDisplay_ErrorDisplayShowNoConnectionModeCode);
	    delay(200);
	  }
	// Finished
	// Insert Code Above
}

void ViewSmartLightDeviceStatus_Behaviour_Impl() {
	// Insert Code Below
	// TheSystemCommunicatesTheExternalLightIntensityStatusOfTheDeviceToTheUserThroughTheLED
	// TheSystemCommunicatesTheInternalNetworkStatusOfTheDeviceToTheUserThroughTheWiFiLED
	// DecideAfterTheSystemCommunicatesTheInternalNetworkStatusOfTheDeviceToTheUserThroughTheWiFiLED
	// TheSystemNotifiesTheUserThroughTheErrorDisplayThatEverythingIsOperational
	// TheSystemNotifiesTheUserThroughTheErrorDisplayThatItCannotConnectToWiFi
	// TheSystemNotifiesTheUserThroughTheErrorDisplayThatItCannotConnectToWiFiRaisingWiFiUnreachable
	// Finished
	// Insert Code Above
}

void DebugHardware_Behaviour_Impl() {
	// Insert Code Below
	// TheDebugButtonSendsInputDataToTheSystem
	// DecideAfterTheDebugButtonSendsInputDataToTheSystem
	int buttonState = DebugButtonMonitored();
	  if (buttonState == HIGH) {
	  	return;
	  }
	// SystemAscertainsThatTheDebugButtonHasBeenPushed
	// DecideAfterSystemAscertainsThatTheDebugButtonHasBeenPushed
	// TheSystemInstructsTheLEDToBlink
	for (int i = 0; i < 3; i++) {
	    updateLED(kLED_LEDTurnOn);
	    delay(200);
	
	    updateLED(kLED_LEDTurnOff);
	    delay(200);
	  }
	// DecideAfterTheSystemInstructsTheLEDToBlink
	// TheSystemInstructsTheWiFiLEDToBlink
	for (int i = 0; i < 3; i++) {
	    updateWiFiLED(kWiFiLED_WiFiLEDTurnOn);
	    delay(200);
	
	    updateWiFiLED(kWiFiLED_WiFiLEDTurnOff);
	    delay(200);
	  }
	// DecideAfterTheSystemInstructsTheWiFiLEDToBlink
	// TheSystemInstructsTheErrorDisplayToBlink
	for (int i = 0; i < 3; i++) {
	    updateErrorDisplay(kErrorDisplay_ErrorDisplayShowNormalModeCode);
	    delay(200);
	
	    updateErrorDisplay(kErrorDisplay_ErrorDisplayShowNoConnectionModeCode);
	    delay(200);
	  }
	// SystemAscertainsThatTheDebugButtonHasNotBeenPushed
	// Finished
	// Insert Code Above
}

void ViewLogs_Behaviour_Impl() {
	// Insert Code Below
	// TheUserRequestsTheLogsFromTheSystem
	// DecideAfterTheUserRequestsTheLogsFromTheSystem
	// TheSystemReturnsTheCopyOfTheLogsToTheUser
	// TheSystemCannotFindAnyLogs
	// TheSystemNotifiesTheUserThatThereAreZeroLogsInTheSystem
	// Finished
	// Insert Code Above
}

void TurnOffSmartLightDevice_Behaviour_Impl() {
	// Insert Code Below
	// Finished
	// Insert Code Above
}



/*
 * Function: operateBoard
 * ----------------------
 *   Controls the board.
 */
void operateBoard() {
  switch (currentMode) {
    case kNormal:
      operateBoardInNormalMode();
      break;
    case kNoConnection:
      operateBoardInNoConnectionMode();
      break;
    default:
      operateBoardDefault();
      break;
  }
  
  delay(100);
}

/*
 * Function: operateBoardDefault
 */
void operateBoardDefault() {
	OperateSmartLightsView_Behaviour();
	
    DisplayErrorCodeHandler();
    ReconnectDeviceHandler();
    RepairDeviceHandler();
}

/*
 * Function: operateBoardInNormalMode
 */
void operateBoardInNormalMode() {
	// Insert Code Below
	operateBoardDefault();
	// Insert Code Above
}

/*
 * Function: operateBoardInNoConnectionMode
 */
void operateBoardInNoConnectionMode() {
	// Insert Code Below
	operateBoardDefault();
	// Insert Code Above
}


/*
 * Function OperateSmartLightsView_Behaviour
 */
void OperateSmartLightsView_Behaviour() {
	if ((handling_LEDFailureRaisedInTurnOnSmartLightDevice_event != 0) || (handling_WiFiLEDFailureRaisedInTurnOnSmartLightDevice_event != 0) || (handling_ErrorDisplayFailureRaisedInTurnOnSmartLightDevice_event != 0) || (handling_LEDFailureRaisedInDebugHardware_event != 0) || (handling_WiFiLEDFailureRaisedInDebugHardware_event != 0) || (handling_ErrorDisplayFailureRaisedInDebugHardware_event != 0) || (handling_WiFiUnreachableRaisedInViewSmartLightDeviceStatus_event != 0) || (handling_WiFiUnreachableRaisedInRecordData_event != 0) ||  false) {
		return;
	}
	OperateSmartLightsBehaviour_Behaviour_Impl();
}

void OperateSmartLightsBehaviour_Behaviour_Impl() {
	// Insert Code Below
	ManageLED_Behaviour_Impl();
	// DeviceDecidesToRepeat
	// Insert Code Above
}

void ManageLED_Behaviour_Impl() {
	// Insert Code Below
	// LDRMonitorsThePhysicalSurrounding
	int light_intensity = LDRMonitored();
	// LDRSendsExternalLightIntensityToSystem
	// DecideAfterLDRSendsExternalLightIntensityToSystem
	if (light_intensity >= 800) {
	    updateLED(kLED_LEDTurnOff);
	  } else {
	    updateLED(kLED_LEDTurnOn);
	  }
	// SystemCalculatesThatLightIntensityThresholdHasBeenReached
	// SystemTurnsOffLED
	// LEDActsOnPhysicalSurroundingByNotProvidingLight
	RecordData_Behaviour_Impl();
	// SystemCalculatesThatLightIntensityThresholdHasNotBeenReached
	// SystemTurnsOnLED
	// LEDActsOnPhysicalSurroundingByProvidingLight
	// Finished
	// Insert Code Above
}

void RecordData_Behaviour_Impl() {
	// Insert Code Below
	// SystemCreatesALogOfTheLightIntensity
	String json = generateJSON("light_intensity", light_intensity);
	  Serial.println(json);
	// SystemTurnsOnWiFiLED
	// SystemConnectsToWiFi
	// DecideAfterSystemConnectsToWiFi
	// SystemRecordsLogOfTheLightIntensity
	// SystemTurnsOffWiFiLED
	// WiFiFailsToSendConfirmation
	// Finished
	// Insert Code Above
}



/*
 * Function updateLED
 */
void updateLED(int val) {
  switch (val) {
    case kLED_LEDTurnOn:
      LEDTurnOn();
      break;
    case kLED_LEDTurnOff:
      LEDTurnOff();
      break;
    default:
      break;
  }
}

/*
 * Function updateLDR
 */
void updateLDR(int val) {
  switch (val) {
    case kLDR_LDRMonitored:
      LDRMonitored();
      break;
    default:
      break;
  }
}

/*
 * Function updateDebugButton
 */
void updateDebugButton(int val) {
  switch (val) {
    case kDebugButton_DebugButtonMonitored:
      DebugButtonMonitored();
      break;
    default:
      break;
  }
}

/*
 * Function updateWiFiLED
 */
void updateWiFiLED(int val) {
  switch (val) {
    case kWiFiLED_WiFiLEDTurnOn:
      WiFiLEDTurnOn();
      break;
    case kWiFiLED_WiFiLEDTurnOff:
      WiFiLEDTurnOff();
      break;
    default:
      break;
  }
}

/*
 * Function updateErrorDisplay
 */
void updateErrorDisplay(int val) {
  switch (val) {
    case kErrorDisplay_ErrorDisplayShowNormalModeCode:
      ErrorDisplayShowNormalModeCode();
      break;
    case kErrorDisplay_ErrorDisplayShowNoConnectionModeCode:
      ErrorDisplayShowNoConnectionModeCode();
      break;
    default:
      break;
  }
}


/*
 * Function: DisplayErrorCodeHandler
 */
void DisplayErrorCodeHandler() {
	if ((handling_WiFiUnreachableRaisedInRecordData_event == 0) &&  true) {
		currentMode = kNormal;
		return;
	} else {
		currentMode = kNoConnection;
		if (attempt_DisplayErrorCodeHandler() != 0) {
			currentMode = kNormal;
			handling_WiFiUnreachableRaisedInRecordData_event = 0;
			return;
		}
	}
}

/*
 * Function: attempt_DisplayErrorCodeHandler
 * ---------
 *   Returns 0 if unsuccessful; otherwise successfully handled exceptions.
 */
int attempt_DisplayErrorCodeHandler() {
	DisplayErrorCodeBehaviour_Behaviour_Impl();
	return 0;
}

void DisplayErrorCodeBehaviour_Behaviour_Impl() {
	// Insert Code Below
	// EnterHandler
	// SystemDeterminesThatItWasNotAbleToConnectToWiFi
	// SystemSendsWiFiUnreachableCodeToErrorDisplay
	// SystemAttemptsToReconnectToWiFi
	// SystemSuccessfullyReconnectsToWiFi
	// SystemSendsMessageToDisplayToStopShowingErrorCode
	// ExitHandler
	// Finish
	// Insert Code Above
}


/*
 * Function: ReconnectDeviceHandler
 */
void ReconnectDeviceHandler() {
	if ((handling_WiFiUnreachableRaisedInViewSmartLightDeviceStatus_event == 0) &&  true) {
		currentMode = kNormal;
		return;
	} else {
		if (attempt_ReconnectDeviceHandler() != 0) {
			currentMode = kNormal;
			handling_WiFiUnreachableRaisedInViewSmartLightDeviceStatus_event = 0;
			return;
		}
	}
}

/*
 * Function: attempt_ReconnectDeviceHandler
 * ---------
 *   Returns 0 if unsuccessful; otherwise successfully handled exceptions.
 */
int attempt_ReconnectDeviceHandler() {
	ReconnectDeviceBehaviour_Behaviour_Impl();
	return 0;
}

void ReconnectDeviceBehaviour_Behaviour_Impl() {
	// Insert Code Below
	// EnterHandler
	// TheSystemNotifiesTheUserThroughTheErrorDisplayThatItCannotConnectToWiFi
	// SystemAttemptsToReconnectToWiFi
	// TheSystemSuccessfullyConnectsToWiFi
	// ExitHandler
	// Finish
	// Insert Code Above
}


/*
 * Function: RepairDeviceHandler
 */
void RepairDeviceHandler() {
	if ((handling_LEDFailureRaisedInTurnOnSmartLightDevice_event == 0) && (handling_WiFiLEDFailureRaisedInTurnOnSmartLightDevice_event == 0) && (handling_ErrorDisplayFailureRaisedInTurnOnSmartLightDevice_event == 0) && (handling_LEDFailureRaisedInDebugHardware_event == 0) && (handling_WiFiLEDFailureRaisedInDebugHardware_event == 0) && (handling_ErrorDisplayFailureRaisedInDebugHardware_event == 0) &&  true) {
		return;
	} else {
		if (attempt_RepairDeviceHandler() != 0) {
			handling_LEDFailureRaisedInTurnOnSmartLightDevice_event = 0;
			handling_WiFiLEDFailureRaisedInTurnOnSmartLightDevice_event = 0;
			handling_ErrorDisplayFailureRaisedInTurnOnSmartLightDevice_event = 0;
			handling_LEDFailureRaisedInDebugHardware_event = 0;
			handling_WiFiLEDFailureRaisedInDebugHardware_event = 0;
			handling_ErrorDisplayFailureRaisedInDebugHardware_event = 0;
			return;
		}
	}
}

/*
 * Function: attempt_RepairDeviceHandler
 * ---------
 *   Returns 0 if unsuccessful; otherwise successfully handled exceptions.
 */
int attempt_RepairDeviceHandler() {
	RepairDeviceBehaviour_Behaviour_Impl();
	return 0;
}

void RepairDeviceBehaviour_Behaviour_Impl() {
	// Insert Code Below
	// EnterHandler
	// TheSystemNotifiesTheUserByBlinkingTheLEDWiFiLEDAndTheErrorDisplay
	// ExitHandler
	// Finish
	// Insert Code Above
}


