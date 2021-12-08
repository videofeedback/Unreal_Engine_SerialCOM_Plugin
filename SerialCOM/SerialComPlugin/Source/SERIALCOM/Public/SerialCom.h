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

	/**
	 * Utility function to convert 4 bytes into an Integer. If the input array's length is not 4, returns 0.
	 *
	 * @param Bytes A byte array with 4 values representing the integer in little-endian format.
	 * @return The final integer value or 0 for an invalid array.
	 */




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