// Input date string
var inputDateString = '{project.metadata.Project date}';
var daysToAdd = {helmut.variable.Days to arquive}; // Number of days to be added

// Function to add days to a date and convert the format
function addDaysToDateString(inputDateString, daysToAdd) {
    // Import Java classes
    var SimpleDateFormat = Java.type('java.text.SimpleDateFormat');
    var Calendar = Java.type('java.util.Calendar');

    // Define input and output date format
    var dateFormat = new SimpleDateFormat('yyyy-MM-dd');

    try {
        // Parse the input date string into a Date object
        var date = dateFormat.parse(inputDateString);

        // Create a Calendar object and set the date
        var calendar = Calendar.getInstance();
        calendar.setTime(date);

        // Add the specified number of days to the calendar
        calendar.add(Calendar.DATE, daysToAdd);

        // Get the new formatted date
        var outputDateString = dateFormat.format(calendar.getTime());

        return outputDateString;
    } catch (e) {
        // Handle errors in parsing or formatting
        print('Error adding days to the date: ' + e);
        return null; // Return null in case of error
    }
}

// Call the function with the input date string
var outputDateString = addDaysToDateString(inputDateString, daysToAdd);

// Return the new formatted date
outputDateString;
