#pragma once
#include <string>
#include <optional>

namespace parser {

	class TextPosition final {};

	class Token {
		virtual ~Token() {}
		const TextPosition mTextPosition;
	};

	class Identifier final : public Token {};
	class Keyword final : public Token {};
	class StringLiteral final : public Token {};
	class IntegerLiteral final : public Token {};
	class FractionLiteral final : public Token {};
	class CharacterLiteral final : public Token {};
	class Separator final : public Token {};
	class Operator final : public Token {};

	enum class Separators {
		leftParenthesis,
		rightParenthesis,
		leftBrace,
		rightBrace,
		leftBracket,
		rightBracket,
		comma,
		dot,
		semicolon,
		colon
	};
	
	enum class Operators {
		add,
		subtract,
		multiply,
		divide,
		and,
		or,
		xor,
		not
	};

	class ParseTree {

	};
	class Parser {

		virtual ~Parser() {}
		virtual ParseTree parse(const std::string& input) = 0;
		virtual std::optional<Identifier> parseIdentifier();

	};

}