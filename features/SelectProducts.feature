Feature: Select a product

	Scenario: Select chips with enough money
        Given a quarter is inserted
        And a quarter is inserted
        When 'CHIPS' are selected
        Then the vending machine displays 'THANK YOU'
