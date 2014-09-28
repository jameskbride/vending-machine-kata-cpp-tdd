Feature: Accept Coins
	Scenario: No coins inserted
	Given no coins are inserted
	Then the vending machine displays 'INSERT COIN'

	Scenario: Accept a nickel
	Given a nickel is inserted
	Then the vending machine displays '0.05'
