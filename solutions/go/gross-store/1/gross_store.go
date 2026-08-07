package gross

// Units stores the Gross Store unit measurements.
func Units() map[string]int {
	return map[string]int{
		"quarter_of_a_dozen": 3,
		"half_of_a_dozen":    6,
		"dozen":              12,
		"small_gross":        120,
		"gross":              144,
		"great_gross":        1728,
	}
}

// NewBill creates a new bill.
func NewBill() map[string]int {
	return map[string]int{}
}

// AddItem adds an item to customer bill.
func AddItem(bill, units map[string]int, item, unit string) bool {
	amount, validUnit := units[unit]
	if validUnit {
		bill[item] += amount
	}
	return validUnit
}

// RemoveItem removes an item from customer bill.
func RemoveItem(bill, units map[string]int, item, unit string) bool {
	amountOnBill, hasItem := bill[item]
	amount, validUnit := units[unit]
	decreasedAmount := amountOnBill - amount
	if !hasItem || !validUnit || decreasedAmount < 0 {
		return false
	} else if decreasedAmount == 0 {
		delete(bill, item)
	} else {
		bill[item] = decreasedAmount
	}
	return true
}

// GetItem returns the quantity of an item that the customer has in his/her bill.
func GetItem(bill map[string]int, item string) (int, bool) {
	amount, hasItem := bill[item]
	return amount, hasItem
}
