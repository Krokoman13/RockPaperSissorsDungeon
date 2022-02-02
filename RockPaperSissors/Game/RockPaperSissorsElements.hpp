#pragma once

enum Element { Rock, Paper, Scissors, NONE};

static Element CounterTo(Element element)
{
	switch (element)
	{
	case Rock:
		return Paper;

	case Paper:
		return Scissors;

	case Scissors:
		return Rock;

	default:
		return NONE;
	}
}

static std::string ToString(Element element)
{
	switch (element)
	{
	case Rock:
		return "Rock";

	case Paper:
		return "Paper";

	case Scissors:
		return "Scissors";

	default:
		return "UNKNOWN";
	}
}