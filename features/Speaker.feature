Feature: Speaker can speak
	Scenario: Speaker can say hello world
		Given A speaker is ready
                When The speaker speaks
                Then The speaker says "Hello World!"
