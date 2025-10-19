#include "rna_transcription.h"
#include <stdexcept>

namespace rna_transcription {

    char to_rna(char nucleotide) {
        switch (nucleotide) {
            case 'A': return 'U';
            case 'T': return 'A';
            case 'G': return 'C';
            case 'C': return 'G';
            default: throw std::invalid_argument("Invalid nucleotide");
        }
    }

    std::string to_rna(const std::string& dna_seq) {
        std::string rna_seq;

        for (char ch: dna_seq) {
            rna_seq.push_back(to_rna(ch));
        }

        return rna_seq;
    }

}  // namespace rna_transcription
