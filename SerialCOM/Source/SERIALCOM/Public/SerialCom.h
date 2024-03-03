#pragma once

#define FC_DTRDSR       0x01
#define FC_RTSCTS       0x02
#define FC_XONXOFF      0x04
#define ASCII_BEL       0x07
#define ASCII_BS        0x08
#define ASCII_LF        0x0A
#define ASCII_CR        0x0D
#define ASCII_XON       0x11
#define ASCII_XOFF      0x13

#include "CoreTypes.h"
#include "SerialCom.generated.h"


// Forward declaration
typedef struct _OVERLAPPED OVERLAPPED;

UENUM(BlueprintType, Category = "Communication Serial")
enum class ELineEnd : uint8
{
	rn	UMETA(DisplayName = "\r\n"),
	n	UMETA(DisplayName = "\n"),
	r	UMETA(DisplayName = "\r"),
	nr	UMETA(DisplayName = "\n\r")
};

/**
 * @enum ESerialDevicesFindFlags
 * @brief Flags to control the behavior of serial device searching.
 *
 * This enumeration contains flags that can be used to control the behavior of functions that search for serial devices.
 * Each flag represents a different search option or constraint.
 */
UENUM(BlueprintType, Category = "Communication Serial Find Flags", meta = (Bitflags, UseEnumValuesAsMaskValuesInEditor = "true"))
enum class ESerialDevicesFindFlags : uint8
{
	/**
	 * @brief Invalid flag.
	 *
	 * This flag cannot be used. It's likely a placeholder or reserved for future usage.
	 */
	ESDFF_Error = 0x00 UMETA(DisplayName = "Error"),
	/**
	 * @brief Partial character match.
	 *
	 * If this flag is set, the search function will match devices whose names contain the search string as a substring.
	 * If this flag is not set, the search function will perform a full character match, only matching devices whose names are exactly the same as the search string.
	 */
	ESDFF_PartialCharacterMatching = 0x01 UMETA(DisplayName = "PartialCharacterMatching"),
	/**
	* @brief Case sensitive.
	*
	* If this flag is set, the search function will perform a case-sensitive search, meaning that "Device1" and "device1" would be considered different names.
	* If this flag is not set, the search function will perform a case-insensitive search.
	*/
	ESDFF_CaseSensitive = 0x02 UMETA(DisplayName = "CaseSensitive"),
	/**
	 * @brief Regular expression match.
	 *
	 * If this flag is set, the search string will be treated as a regular expression and the search function will match devices whose names match the regular expression.
	 * This flag can only be used alone, not in combination with other flags.
	 */
	ESDFF_RegularExpressionMatching = 0x04 UMETA(DisplayName = "RegularExpressionMatching(Multiple Choice)"),

};

ENUM_CLASS_FLAGS(ESerialDevicesFindFlags);

USTRUCT(BlueprintType)
struct FSerialPortInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	int32 Port = -1;
	UPROPERTY(BlueprintReadWrite)
	FString PortName;
	UPROPERTY(BlueprintReadWrite)
	FString Description;

	//define constructs
	FSerialPortInfo() = default;
	FSerialPortInfo(int32 InPort, FString InPortName, FString InDescription)
	{
		Port = InPort;
		PortName = InPortName;
		Description = InDescription;
	}
	FSerialPortInfo(const FSerialPortInfo& Other) = default;
	FSerialPortInfo& operator=(const FSerialPortInfo& Other)
	{
		this->Port = Other.Port;
		this->PortName = Other.PortName;
		this->Description = Other.Description;
		return *this;
	}
	FSerialPortInfo(FSerialPortInfo&& Other) = default;

};

UCLASS(BlueprintType, Category = "Communication Serial", meta = (Keywords = "com arduino serial arduino duino"))
class SERIALCOM_API USerialCom : public UObject
{
	GENERATED_BODY()

public:
	/** Determines the line ending used when writing lines to serial port with PrintLine. */
	UPROPERTY(BlueprintReadWrite, Category = "Communication Serial | String")
		ELineEnd WriteLineEnd;

public:
	USerialCom();
	~USerialCom();

	/**
	 * Open a serial port and return the created Serial instance.
	 * Don't forget to close the port before exiting the game.
	 *
	 * @param bOpened If the serial port was successfully opened.
	 * @param Port The serial port to open.
	 * @param BaudRate BaudRate to open the serial port with.
	 * @param DTR Enable/Disable DTR communication protocol.
	 * @param RTS Enable/Disable RTS communication protocol.
	 * @return A Serial instance to work with the opened port.
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Open Serial Port With Flow Control"), Category = "Communication Serial", meta = (Keywords = "communication com SERIALCOM duino arduino serial port start open serial with flow control"))
		static USerialCom* OpenComPortWithFlowControl(bool &bOpened, int32 Port = 1, int32 BaudRate = 9600, bool DTR = true, bool RTS = true);

		/*
		* This function scans the system for all serial port devices and collects their names and port numbers. 
		* It returns an array of FSerialPortInfo objects, each containing the name and port number of a serial port device.
		*
		* @return All serial port devices and port numbers structure
		*/
		UFUNCTION(BlueprintPure, Category = "Communication Serial")
		static TArray<FSerialPortInfo> GetAllSerialPortDevicesAndPortNumbers();
		/**
		* @brief Find the port number of a serial port device.
		*
		* This function attempts to find the port number of a specific serial port device based on its name.
		* If the device is found, the function returns true and the port number is stored in the reference parameter 'FindComPort'.
		* If the device is not found, the function returns false.
		*
		* @param DeviceName  - The name of the serial port device to find.
		* @param FindComPort - A reference parameter where the found port number will be stored.
		* @param FindFlags   - Flags to control the search behavior .
		*
		* @return bool - Returns true if the device is found, false otherwise.
		*/
		UFUNCTION(BlueprintPure, Category = "Communication Serial",meta = (Keywords = "communication com SERIALCOM duino arduino serial port serial FindPor FindCom"))
		static bool FindSerialPortDevicePortNumber(FString DeviceName, int32& FindComPort, UPARAM(meta = (Bitmask, BitmaskEnum = ESerialDevicesFindFlags)) int32 FindFlags = 0x01);

		/**
		* @brief Find the port numbers and information of a serial port device.
		*
		* This function attempts to find the port numbers and related information of a specific serial port device based on its name.
		 * If the device is found, the function returns an array of FSerialPortInfo structure, each containing the port number and information of a matching device.
		 *
		 * @param DeviceName - The name of the serial port device to find.
		 *
		* @param FindFlags - Flags to control the search behavior (the specific meaning of the flags depends on the implementation).
		 *
		* @return TArray<FSerialPortInfo> - Returns an array of FSerialPortInfo structure if the device is found. Each FSerialPortInfo object contains the port number and information of a matching device.
		*/
		UFUNCTION(BlueprintPure, Category = "Communication Serial", meta = (Keywords = "communication com SERIALCOM duino arduino serial port serial FindPor FindCom"))
		static TArray<FSerialPortInfo> FindAllSerialPortDevicePortInfo(FString DeviceName, UPARAM(meta = (Bitmask, BitmaskEnum = ESerialDevicesFindFlags)) int32 FindFlags = 0x01);

		/**
 * @brief Find and open a serial port by device name.
 *
 * This function attempts to find a serial port device by its name and open it. If the device is found and the port is not occupied,
 * the function returns a valid USerialCom object and sets the 'bOpened' reference parameter to true. If the port is occupied,
 * the function still returns a valid USerialCom object, but sets 'bOpened' to false. If the device is not found, the function returns a null pointer.
 *
 * @param DeviceName - The name of the serial port device to find and open.
 * @param FindFlags - Flags to control the search behavior (the specific meaning of the flags depends on the implementation).
 * @param bOpened - A reference parameter that indicates whether the port was successfully opened (true) or not (false).
 * @param FindComPort - A reference parameter where the found port number will be stored.
 * @param Port - The port number to open (default is 1).
 * @param BaudRate - The baud rate to use when opening the port (default is 9600).
 *
 * @return USerialCom* - Returns a valid USerialCom object if the device is found, null otherwise. Even if the port is occupied, a valid USerialCom object is returned.
 */
		UFUNCTION(BlueprintCallable, meta = (DisplayName = "Open Serial Port"), Category = "Communication Serial", meta = (Keywords = "communication com SERIALCOM duino arduino serial port start open serial"))
		static USerialCom* FindAndOpenSerialPortByDeviceName(FString DeviceName, bool& bOpened, int32& FindComPort, UPARAM(meta = (Bitmask, BitmaskEnum = ESerialDevicesFindFlags)) int32 FindFlags = 0x01, int32 BaudRate = 9600);



//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Open Serial Port"), Category = "Communication Serial", meta = (Keywords = "communication com SERIALCOM duino arduino serial port start open serial"))
		static USerialCom* OpenComPort(bool &bOpened, int32 Port = 1, int32 BaudRate = 9600);

	/**
	 * Utility function to convert 4 bytes into an Integer. If the input array's length is not 4, returns 0.
	 *
	 * @param Bytes A byte array with 4 values representing the integer in little-endian format.
	 * @return The final integer value or 0 for an invalid array.
	 */



//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////




	UFUNCTION(BlueprintPure, meta = (DisplayName = "Serial Bytes to Int"), Category = "Communication Serial", meta = (Keywords = "communication com SERIALCOM duino arduino serial cast concatenate group bit bitwise bytes to int"))
		static int32 BytesToInt(TArray<uint8> Bytes);

	/**
	 * Utility function to get the 4 bytes that make an integer.
	 *
	 * @param Int The integer value to be converted.
	 * @return A byte array containing the 4 bytes that make the integer, starting from the least significant one (little endian).
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Serial Int to Bytes"), Category = "Communication Serial", meta = (Keywords = "communication com SERIALCOM duino arduino serial cast separate bit bitwise int to bytes"))
		static TArray<uint8> IntToBytes(const int32& Int);

	/**
	 * Utility function to convert 4 bytes into a float. If the input array's length is not 4, returns 0.0.
	 *
	 * @param Bytes A byte array with 4 values representing the float in IEEE 754 standard format.
	 * @return The final float value or 0.0 for an invalid array.
	 */
	
	
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Serial Bytes to Float"), Category = "Communication Serial", meta = (Keywords = "communication com SERIALCOM duino arduino serial cast concatenate group bit bitwise bytes to float"))
		static float BytesToFloat(TArray<uint8> Bytes);

	/**
	 * Utility function to get the 4 bytes that make a float.
	 *
	 * @param Float The float value to be converted.
	 * @return A byte array containing the 4 bytes that make the float, in IEEE 754 standard format.
	 */


	UFUNCTION(BlueprintPure, meta = (DisplayName = "Serial Float to Bytes"), Category = "Communication Serial", meta = (Keywords = "communication com SERIALCOM duino arduino serial cast separate bit bitwise flowat to bytes"))
		static TArray<uint8> FloatToBytes(const float& Float);

	/**
	 * Open a serial port. Don't forget to close the port before exiting the game.
	 * If this Serial instance has already an opened port,
	 * return false and doesn't change the opened port number.
	 *
	 * @param Port The serial port to open.
	 * @param BaudRate BaudRate to open the serial port with.
	 * @param DTR enable/disable DTR protocol
	 * @param RTS enable/disable RTS protocol
	 * @return If the serial port was successfully opened.
	 */

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////


	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Open Serial Port With Target and Flow Control"), Category = "Communication Serial", meta = (Keywords = "communication com SERIALCOM duino arduino serial start init open port"))
		bool OpenWFC(int32 Port = 2, int32 BaudRate = 9600, bool DTR = true, bool RTS = true);
	/**
	 * Close and end the communication with the serial port. If not open, do nothing.
	 */

////////////////////////////////////////////////////////////////////



	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Close Serial Port"), Category = "Communication Serial", meta = (Keywords = "communication com SERIALCOM duino arduino serial end finish release close port"))
		void Close();

	/**
	 * Will read characters from Serial port until \0 (null char) is found or there are no
	 * characters left to read.
	 *
	 * @param bSuccess If there was anything to read.
	 * @return The read string
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Serial Read String", keywords = "read string communication com SERIALCOM duino arduino serial get read receive string words text characters"), Category = "Communication Serial")
		FString ReadString(bool& bSuccess);
	/**
	 * Will read characters from Serial port until \r\n (Arduino println line end) is found.
	 *
	 * @param bSuccess If there was anything to read.
	 * @return The read string
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Serial Read Line", keywords = "communication com SERIALCOM duino arduino serial read line get read receive string words text characters"), Category = "Communication Serial")
		FString Readln(bool& bSuccess);
	/**
	 * Reads the string until a specific char is met.
	 * The Terminator char won't be included in the result string.
	 */
	 //UFUNCTION(BlueprintCallable, meta = (DisplayName = "Read String Until", keywords = "get read receive string words text characters"), Category = "Communication Serial")
	FString ReadStringUntil(bool& bSuccess, uint8 Terminator);
	/**
	 * Reads a float from the serial port (sent as 4 bytes).
	 * @param bSuccess True if there were 4 bytes to read.
	 * @return The read value
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Serial Read Float", keywords = "communication com SERIALCOM duino arduino serial read a float get read receive"), Category = "Communication Serial")
		float ReadFloat(bool& bSuccess);
	/**
	 * Reads an integer from the serial port (sent as 4 bytes).
	 * @param bSuccess True if there were 4 bytes to read.
	 * @return The read value
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Serial Read Int", keywords = "communication com SERIALCOM duino arduino serial read an int get read receive integer"), Category = "Communication Serial")
		int32 ReadInt(bool& bSuccess);
	/**
	 * Reads a byte from the serial port.
	 * @param bSuccess True if there were 4 bytes to read.
	 * @return The read value
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Serial Read Byte", keywords = "communication com SERIALCOM duino arduino serial read a byte get read receive"), Category = "Communication Serial")
		uint8 ReadByte(bool& bSuccess);
	/**
	 * Reads up to Limit bytes from the serial port. If there are less than Limit,
	 * reads all of them and return True.
	 * @param bSuccess True if there was at least 1 byte to read.
	 * @return An array containing the read bytes
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Serial Read Bytes", keywords = "communication com SERIALCOM duino arduino serial read bytes get read receive"), Category = "Communication Serial")
		TArray<uint8> ReadBytes(int32 Limit = 256);

	/**
	 * Writes a string without newline to the serial port.
	 * @param String The string to be sent to the serial port.
	 * @return True if the string was sent.
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Serial Print", keywords = "communication com SERIALCOM duino arduino serial print send write string words text characters"), Category = "Communication Serial")
		bool Print(FString String);
	/**
	 * Writes a string with newline (\n) appended at the end to the serial port.
	 * @param String The string to be sent to the serial port.
	 * @return True if the string was sent.
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Serial Print Line", keywords = "communication com SERIALCOM duino arduino serial print line send write string words text characters"), Category = "Communication Serial")
		bool Println(FString String);
	/**
	 * Writes a float value to the serial port as 4 bytes.
	 * @param Value The value to be sent to the serial port.
	 * @return True if the bytes were sent.
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Serial Write Float", keywords = "communication com SERIALCOM duino arduino serial write a float send"), Category = "Communication Serial")
		bool WriteFloat(float Value);
	/**
	 * Writes an integer value to the serial port as 4 bytes.
	 * @param Value The value to be sent to the serial port.
	 * @return True if the bytes were sent.
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Serial Write Int", keywords = "communication com SERIALCOM duino arduino serial write an int integer send"), Category = "Communication Serial")
		bool WriteInt(int32 Value);
	/**
	 * Writes a byte value to the serial port.
	 * @param Value The value to be sent to the serial port.
	 * @return True if the byte was sent.
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Serial Write Byte", keywords = "communication com SERIALCOM duino arduino serial write a byte send"), Category = "Communication Serial")
		bool WriteByte(uint8 Value);
	/**
	 * Writes a byte array as a sequence of bytes to the serial port.
	 * @param Buffer The byte array to be sent to the serial port.
	 * @return True if the bytes were sent.
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Serial Write Bytes", keywords = "communication com SERIALCOM duino arduino serial write bytes send"), Category = "Communication Serial")
		bool WriteBytes(TArray<uint8> Buffer);

	/** Clean the serial port by reading everything left to be read. */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Flush Serial Port"), Category = "Communication Serial")
		void Flush();

	/**
	 * Check if the serial port is open.
	 * @return True if the serial port is open.
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Is Serial Port Open?"), Category = "Communication Serial")
		bool IsOpened() { return m_hIDComDev != NULL; }

	/**
	 * Read the number of the serial port selected for this Serial instance.
	 * @return The number of the serial port.
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Serial Port Number"), Category = "Communication Serial")
		int32 GetPort() { return m_Port; }

	/**
	 * Read the selected BaudRate for this Serial instance.
	 * @return The baud rate.
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Serial Port Baud Rate"), Category = "Communication Serial")
		int32 GetBaud() { return m_Baud; }

	/**
	 * Converts a LineEnd enum value to String.
	 * @param LineEnd LineEnd enum value.
	 * @return The LineEnd value in string format.
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Serial Line End to String", keywords = "communication com SERIALCOM duino arduino serial cast convert line end to string"), Category = "Communication Serial")
		FString LineEndToStr(ELineEnd LineEnd);





/////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
/*

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "New Baudrate", keywords = "communication com arduino serial cast convert line end to string"), Category = "Communication Serial")
		FString LineEndToStrBD(ELineEnd LineEnd);

*/

/////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////






protected:
	void* m_hIDComDev;

	// These are pointers to be able to use OVERLAPPED with forward declaration
	OVERLAPPED* m_OverlappedRead;
	OVERLAPPED* m_OverlappedWrite;

	int32 m_Port;
	int32 m_Baud;

};