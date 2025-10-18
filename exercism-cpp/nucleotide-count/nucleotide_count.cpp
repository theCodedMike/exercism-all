#include "nucleotide_count.h"
#include <stdexcept>

namespace nucleotide_count {

    counter_map count(const std::string_view dna_sequence) {
        counter_map nucleotide_counter = {
            {'A', 0},
            {'C', 0},
            {'G', 0},
            {'T', 0}
        };

        for (char nucleotide: dna_sequence) {
            if (nucleotide != 'A' && nucleotide != 'C' && nucleotide != 'G' && nucleotide != 'T')
                throw std::invalid_argument("");

            ++nucleotide_counter[nucleotide];
        }

        return nucleotide_counter;
    }

}  // namespace nucleotide_count
