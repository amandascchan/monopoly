sed -i 's/^\(.* cout.*\)$/#ifdef toilet\n\1\n#endif/' file
