using System;

public class CircularBuffer<T>
{
    private readonly T[] _buffer;
    private readonly int _capacity;
    private int _count;
    private int _readIdx;
    private int _writeIdx;
    public CircularBuffer(int capacity)
    {
        _buffer = new T[capacity];
        _capacity = capacity;
        _count = 0;
        _readIdx = 0;
        _writeIdx = 0;
    }

    public T Read()
    {
        if (IsEmpty())
            throw new InvalidOperationException();
        _count--;
        T temp = _buffer[_readIdx];
        _readIdx = (_readIdx + 1) % _capacity;
        return temp;
    }

    private bool IsEmpty() => _count == 0;
    private bool IsFull() => _count == _capacity;
    public void Write(T value)
    {
        if (IsFull())
            throw new InvalidOperationException();
        _count++;
        _buffer[_writeIdx] = value;
        _writeIdx = (_writeIdx + 1) % _capacity;
    }

    public void Overwrite(T value)
    {
        if (IsFull())
            _readIdx = (_readIdx + 1) % _capacity;
        else
            _count++;
        _buffer[_writeIdx] = value;
        _writeIdx = (_writeIdx + 1) % _capacity;
    }

    public void Clear()
    {
        _count = 0;
        _readIdx = 0;
        _writeIdx = 0;
    }
}