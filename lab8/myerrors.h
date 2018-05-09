#pragma once

#include <stdexcept>
#include <iostream>

namespace myerrors {

	class calc_error : public std::runtime_error {
	public:

		calc_error(const std::runtime_error* err, const char* text, const char* file, int line) : std::runtime_error("asd"),
		parent(err), text(text), file(file), line(line) { }

		const std::runtime_error* get_parent() { return parent; }
		const std::runtime_error* parent;
		const char* text;
		const char* file;
		int line;

	};

	static void handler() {
		try { // lippincott function
  	  throw;

		} catch (const calc_error* err) {
			std::cout << "Exception in: ";
			const std::runtime_error* current = err;

			do {
				const calc_error* calc = dynamic_cast<const calc_error*>(current);
				if (calc != nullptr) {
					std::cout << "because of: " << calc->text <<" [in file: " << calc->file << " in line: " << calc->line << "]" << std::endl;
					current = calc->parent;
				}
				else {
					std::cout << current->what() << std::endl;
					current = nullptr;
				}
			} while (current != nullptr);
		}
	}
};
