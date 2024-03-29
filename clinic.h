/*
*****************************************************************************
File: clinic.h
Full Name  : Yuchi Zheng
*****************************************************************************
*/

// SAFE-GUARD: 
// It is good practice to apply safe-guards to header files
// Safe-guard's ensures only 1 copy of the header file is used in the project build
// The macro name should be mirroring the file name with _ for spaces, dots, etc.
#ifndef CLINIC_H
#define CLINIC_H


//////////////////////////////////////
// Module macro's (usable by any file that includes this header)
//////////////////////////////////////

// Display formatting options (Provided to student)
// !!! DO NOT MODIFY THESE MACRO'S !!!
#define FMT_FORM 1
#define FMT_TABLE 2

// C Strings: array sizes
#define NAME_LEN 15
#define PHONE_DESC_LEN 4
#define PHONE_LEN 10


// MS#3 Additional macro's:
#define FMT_ALL_RECORDS 1
#define FMT_INCLUDE_DATE_FIELD 2

#define MIN_MONTH  1
#define MAX_MONTH  12
#define MIN_DAY    1
#define MIN_HOUR   0 
#define MAX_HOUR   23
#define MIN_MINUTE 0 
#define MAX_MINUTE 59

#define MIN_START_HOUR_APPOINT 10
#define MAX_END_HOUR_APPOINT   14

#define APPOINT_MIN_INTERVAL 30


//////////////////////////////////////
// Structures
//////////////////////////////////////

// Data type: Phone
struct Phone
{
    char description[PHONE_DESC_LEN + 1];
    char number[PHONE_LEN + 1];
};


// Data type: Patient 
struct Patient
{
    int patientNumber;
    char name[NAME_LEN + 1];
    struct Phone phone;
};

// ------------------- MS#3 -------------------

// Data type: Time
struct Time
{
    int hour;
    int min;
};

// Data type: Date
struct Date
{
    int year;
    int month;
    int day;
};

// Data type: Appointment
struct Appointment
{
    int patientNumber;  
    struct Date date;
    struct Time time;
};

// ClinicData type: Provided to student
// !!! DO NOT MODIFY THIS DATA TYPE !!!
struct ClinicData
{
    struct Patient* patients;
    int maxPatient;
    struct Appointment* appointments;
    int maxAppointments;
};


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// Display's the patient table header (table format)
void displayPatientTableHeader(void);

// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt);

// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords);

// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField);


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// 1.Menu: Main
void menuMain(struct ClinicData* data);

// 2.Menu: Patient Management
void menuPatient(struct Patient patient[], int max);

// 3.Menu: Patient edit
void menuPatientEdit(struct Patient* patient);

// 4.Menu: Appointment Management
void menuAppointment(struct ClinicData* data);

// 5.Display's all patient data in the FMT_FORM | FMT_TABLE format
void displayAllPatients(const struct Patient patient[], int max, int fmt);

// 6.Search for a patient record based on patient number or phone number
void searchPatientData(const struct Patient patient[], int max);

// 7.Add a new patient record to the patient array
void addPatient(struct Patient patient[], int max);

// 8.Edit a patient record from the patient array
void editPatient(struct Patient patient[], int max);

// 9.Remove a patient record from the patient array
void removePatient(struct Patient patient[], int max);



// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
void viewAllAppointments(struct ClinicData* data);    

// View appointment schedule for the user input date
void viewAppointmentSchedule(struct ClinicData* data);     

// Add an appointment record to the appointment array
void addAppointment(struct Appointment appoints[], int maxAppoints,
                    struct Patient patients[], int maxPatient);          

// Remove an appointment record from the appointment array
void removeAppointment(struct Appointment appoints[], int maxAppoints,
                       struct Patient patients[], int maxPatient);       



//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
void searchPatientByPatientNumber(const struct Patient patient[], int max);

// Search and display patient records by phone number (tabular)
void searchPatientByPhoneNumber(const struct Patient patient[], int max);

// Get the next highest patient number
int nextPatientNumber(const struct Patient patient[], int max);

// Find the patient array in    dex by patient number (returns -1 if not found)
int findPatientIndexByPatientNum(int patientNumber,
                                 const struct Patient patient[], int max);


// NEW FUNCTION 
// Sort the appointments by date and time in ascending order                  
void sortAppointsByDateTime(struct Appointment appoints[], int max);

// NEW FUNCTION
// Check whether the user's input year is a leap year or not                      
// Return the days of February related to the inputting year
int isLeapYear(const int inputYear);

// NEW FUNCTION
// Return the days of Month according to the input year and month             
int getMonthDays(const int inputYear, const int inputMonth);

// NEW FUNCTION
// Find the appoinment array index by patient number (returns -1 if not found) 
int findAppointIndexByPatientNum(int patientNumber,
                                 const struct Appointment appoints[], int max);

// NEW FUNCTION
// Validate it for an input appointment time (returns 0 if not valid)  
int isValidAppointTime(const struct Appointment appoint);



//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
void inputPatient(struct Patient* patient);

// Get user input for phone contact information
void inputPhoneData(struct Phone* phone);

// NEW FUNCTION 
// Get user input for year, month and day                               
void inputDate(struct Date* date);

// NEW FUNCTION
// Get user input for hour and minute                                      
void inputTime(struct Time* time);

// NEW FUNCTION 
// Get user input for a patient number of a new appointment record
// Search and check whether the input patient number is in the list of patient info file     
void inputPatientNumber(int* patientNumber, struct Patient patients[], int maxPatient);

// NEW FUNCTION
// Get user input for a new appointment record      
void inputAppointmentData(struct Appointment* appoint,
                          const struct Appointment appoints[], int max);



//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
int importPatients(const char* datafile, struct Patient patients[], int max);

// Import appointment data from file into an Appointment array (returns # of records read)
int importAppointments(const char* datafile, struct Appointment appoints[], int max);


#endif // !CLINIC_H


