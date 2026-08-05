// Package gigasecond manipulates time values based by quantities of
// 1000 million seconds 
package gigasecond

import "time"

// AddGigasecond adds 1000 million seconds to it's argument
func AddGigasecond(t time.Time) time.Time {
	return t.Add(time.Second * 1000000000)
}