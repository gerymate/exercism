package booking

import (
	"fmt"
	"time"
)

// Schedule returns a time.Time from a string containing a date
func Schedule(date string) time.Time {
	// example date: 7/25/2019 13:45:00
	const timeFormat = "1/2/2006 15:04:05"
	t, err := time.Parse(timeFormat, date)
	if err != nil {
		fmt.Println(err)
	}
	return t
}

// HasPassed returns whether a date has passed
func HasPassed(date string) bool {
	// example date: "July 25, 2019 13:45:00"
	const timeFormat = "January 2, 2006 15:04:05"
	t, err := time.Parse(timeFormat, date)
	if err != nil {
		fmt.Println(err)
	}
	return t.Before(time.Now())
}

// IsAfternoonAppointment returns whether a time is in the afternoon
func IsAfternoonAppointment(date string) bool {
	// example date: "Thursday, July 25, 2019 13:45:00"
	const timeFormat = "Monday, January 2, 2006 15:04:05"
	t, err := time.Parse(timeFormat, date)
	if err != nil {
		fmt.Println(err)
	}
	hour := t.Hour()
	return 12 <= hour && hour < 18
}

// Description returns a formatted string of the appointment time
func Description(date string) string {
	// date format is the same as to the Schedule function
	t := Schedule(date)
	t_formatted := t.Format("Monday, January 2, 2006, at 15:04")
	return fmt.Sprintf("You have an appointment on %v.", t_formatted)
}

// AnniversaryDate returns a Time with this year's anniversary
func AnniversaryDate() time.Time {
	return time.Date(time.Now().Year(), 9, 15, 0, 0, 0, 0, time.UTC)
}
