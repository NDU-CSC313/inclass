#include <utility>
#define _CONSTEXPR20 constexpr 
#define _STD std::
#define _DEBUG_LT_PRED(pred, x, y) static_cast<bool>(pred(x, y))

template <class _RanIt, class _Pr>
_CONSTEXPR20 void Med3_unchecked(_RanIt _First, _RanIt _Mid, _RanIt _Last, _Pr _Pred) {
    // sort median of three elements to middle
    if (_DEBUG_LT_PRED(_Pred, *_Mid, *_First)) {
        _STD iter_swap(_Mid, _First);
    }

    if (_DEBUG_LT_PRED(_Pred, *_Last, *_Mid)) { // swap middle and last, then test first again
        _STD iter_swap(_Last, _Mid);

        if (_DEBUG_LT_PRED(_Pred, *_Mid, *_First)) {
            _STD iter_swap(_Mid, _First);
        }
    }
}


template <typename Cont, class _RanIt, class _Pr>
_CONSTEXPR20 std::pair<_RanIt, _RanIt> Partition_by_median_guess_unchecked(Cont& cont,_RanIt _First, _RanIt _Last, _Pr _Pred) {
    // partition [_First, _Last), using _Pred
    _RanIt _Mid = _First + ((_Last - _First) >> 1); // shift for codegen
    Med3_unchecked(_First, _Mid, _Prev_iter(_Last), _Pred);
    _RanIt _Pfirst = _Mid;
    _RanIt _Plast = _Next_iter(_Pfirst);

    while (_First < _Pfirst && !_DEBUG_LT_PRED(_Pred, *_Prev_iter(_Pfirst), *_Pfirst)
        && !_Pred(*_Pfirst, *_Prev_iter(_Pfirst))) {
        --_Pfirst;
    }

    while (_Plast < _Last && !_DEBUG_LT_PRED(_Pred, *_Plast, *_Pfirst) && !_Pred(*_Pfirst, *_Plast)) {
        ++_Plast;
    }

    _RanIt _Gfirst = _Plast;
    _RanIt _Glast = _Pfirst;

    for (;;) { // partition
        for (; _Gfirst < _Last; ++_Gfirst) {
            if (_DEBUG_LT_PRED(_Pred, *_Pfirst, *_Gfirst)) {
            }
            else if (_Pred(*_Gfirst, *_Pfirst)) {
                break;
            }
            else if (_Plast != _Gfirst) {
                _STD iter_swap(_Plast, _Gfirst);
                ++_Plast;
            }
            else {
                ++_Plast;
            }
        }

        for (; _First < _Glast; --_Glast) {
            if (_DEBUG_LT_PRED(_Pred, *_Prev_iter(_Glast), *_Pfirst)) {
            }
            else if (_Pred(*_Pfirst, *_Prev_iter(_Glast))) {
                break;
            }
            else if (--_Pfirst != _Prev_iter(_Glast)) {
                _STD iter_swap(_Pfirst, _Prev_iter(_Glast));
            }
        }

        if (_Glast == _First && _Gfirst == _Last) {
            return std::pair<_RanIt, _RanIt>(_Pfirst, _Plast);
        }

        if (_Glast == _First) { // no room at bottom, rotate pivot upward
            if (_Plast != _Gfirst) {
                _STD iter_swap(_Pfirst, _Plast);
            }

            ++_Plast;
            _STD iter_swap(_Pfirst, _Gfirst);
            ++_Pfirst;
            ++_Gfirst;
        }
        else if (_Gfirst == _Last) { // no room at top, rotate pivot downward
            if (--_Glast != --_Pfirst) {
                _STD iter_swap(_Glast, _Pfirst);
            }

            _STD iter_swap(_Pfirst, --_Plast);
        }
        else {
            _STD iter_swap(_Gfirst, --_Glast);
            ++_Gfirst;
        }
    }
}