  /* This procedure works for finding the bit in the nth position. The only thing left to do is to create a number with only the one bit in the correct position turned on.
  These are just powers of two, so one approach might be to do something like:
  // 1      00001
  // 2      00010
  // 4      00100
  // 8      01000
  // 16     10000

  */
 
 
 int is_in_use(int car_num)
{
    return in_use & 1<<car_num;
}

void set_in_use(int car_num)
{
    in_use = in_use | 1<<car_num;
}