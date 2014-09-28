Feature: Accept Coins
	Scenario: No coins inserted
	Given no coins are inserted
	Then the vending machine displays 'INSERT COIN'
