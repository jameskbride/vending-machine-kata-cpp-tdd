Feature: Accept Coins
	Scenario: No coins inserted
	Given no coins are inserted
	Then the vending machine displays 'INSERT COIN'

	Scenario: Accept a nickel
	Given a nickel is inserted
	Then the vending machine displays '0.05'

        Scenario: Accept a dime
        Given a dime is inserted
        Then the vending machine displays '0.10'

        Scenario: Accept a quarter
        Given a quarter is inserted
        Then the vending machine displays '0.25'

        Scenario: Don't accept an invalid coin
        Given a 'penny' is inserted
        Then the vending machine displays 'INSERT COIN'
