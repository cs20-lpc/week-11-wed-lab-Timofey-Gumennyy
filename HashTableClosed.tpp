template <typename T>
int HashTableClosed<T>::insert(const T& key)
{
    // TO DO:
    int probes = 0;
    int index = 0;
    for (int i = 0; occupied[index]; i++)
    {
        index = probeIndex(key, i);
        probes++;
    }
    occupied[index] = true;
    table[index] = key;

    return probes;
}

template <typename T>
pair<bool, int> HashTableClosed<T>::search(const T& key) const
{
    // TO DO:
    int probes = 0;
    int index = 0;
    for (int i = 0; occupied[index]; i++)
    {
        index = probeIndex(key, i);
        probes++;
        if (table[index] == key) return {true, probes};
    }

    return {false, probes};
}
